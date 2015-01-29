/* This file is part of COVISE.

   You can use it under the terms of the GNU Lesser General Public License
   version 2.1 or later, see lgpl-2.1.txt.

 * License: LGPL 2+ */

/**\file
 * \brief class coBaseCoviseInteractor
 * 
 * \author Martin Aumüller <aumueller@hlrs.de>
 * \author (c) 2013 HLRS
 *
 * \copyright GPL2+
 */

#include <util/common.h>
#include <cover/coVRPluginSupport.h>
#include <cover/coVRMSController.h>
#include <cover/RenderObject.h>

#include "coBaseCoviseInteractor.h"

#undef VERBOSE

using namespace covise;
using namespace opencover;

coBaseCoviseInteractor::coBaseCoviseInteractor(const char *n, RenderObject *o, const char *attrib)
{
    // copy the name of the
    d_objName = new char[strlen(n) + 1];
    strcpy(d_objName, n);
    d_object = o;

    char *attr = new char[strlen(attrib) + 1];
    strcpy(attr, attrib);

    char *cp = attr;
    while (*cp && *cp != '\n') // XStarCD
        cp++;
    if (*cp)
        cp++;

    while (*cp && *cp != '\n') // 1
        cp++;
    if (*cp)
        cp++;
    while (*cp && *cp != '\n') // vision.rus.uni-stuttgart.de
        cp++;
    if (*cp)
        cp++;

    char *endOfInfo = cp; // StarCD
    while (*cp && *cp != '\n')
        cp++;
    *cp = '\0';

    d_pluginName = new char[strlen(endOfInfo) + 1]; // Module name

    strcpy(d_pluginName, endOfInfo);

    *endOfInfo = '\0';
    d_feedbackInfo = new char[strlen(attr) + 1]; // the part the system created
    strcpy(d_feedbackInfo, attr);

    d_moduleName = new char[strlen(d_feedbackInfo) + 1];
    d_moduleHost = new char[strlen(d_feedbackInfo) + 1];
    if (sscanf(d_feedbackInfo, "%s\n%d\n%s\n", d_moduleName, &d_moduleInstance, d_moduleHost) != 3)
    {
        cerr << "coBaseCoviseInteractor::coBaseCoviseInteractor: sscanf failed" << endl;
    }
    if (strlen(d_moduleName) > 0)
    {
        memmove(d_moduleName, d_moduleName + 1, strlen(d_moduleName));
        if (d_moduleName[strlen(d_moduleName) - 1] == '_')
            d_moduleName[strlen(d_moduleName) - 1] = '\0';
    }
    if (d_moduleHost[0] == '_')
        strcpy(d_moduleHost, d_moduleHost + 1);

    cp++;
    d_infoString = new char[strlen(cp) + 1]; // The string the user sent
    strcpy(d_infoString, cp);

    delete[] attr;

    /////////////////// aw: Split attribs generated by coFeedback

    d_param = NULL;
    d_user = NULL;
    d_splitString = NULL;

    // If this wasn't created by a coFeedback object ...
    if (strstr(d_infoString, "coFeedback:") != d_infoString)
    {
        d_numUser = 0;
        d_numPara = 0;
    }
    // ok, copy and split the string
    else
    {
        char *splitPtr = d_infoString + strlen("coFeedback:");
        d_splitString = strcpy(new char[strlen(splitPtr) + 1], splitPtr);
        splitPtr = d_splitString;

        // first read the numbers of parameters we will receive
        unsigned int i;
        int retval = sscanf(splitPtr, "%d %d", &d_numPara, &d_numUser);
        if (retval < 2)
            cerr << "Error receiving coFeedback:\n"
                 << "     Couldn't read d_numPara,d_numUser in '" << splitPtr << endl;
#ifdef VERBOSE
        else
            cerr << "Received Interactor: "
                 << d_numPara << " Param, " << d_numUser << " User strings."
                 << endl;
#endif

        d_param = new paraRec[d_numPara + 1]; // +1 for illegal
        d_user = new char *[d_numUser + 1];

        d_param[d_numPara].name = "ILLEGAL";
        d_param[d_numPara].type = "NO TYPE";
        d_param[d_numPara].value = "NO VALUE";
        d_user[d_numUser] = (char *)"NO USER STRING";

        // no args...
        if (!d_numPara && !d_numUser)
            return;

        // skip onto first '!'
        while (*splitPtr && *splitPtr != '!')
            splitPtr++;

        if (!splitPtr)
        {
            cerr << "Error receiving coFeedback:\n"
                 << "     Couldn't read parameters in '" << splitPtr << endl;
        }

        splitPtr++; // skip '!'

        ////// Read Parameters
        for (i = 0; i < d_numPara; i++)
        {
            //// read name
            d_param[i].name = splitPtr;
            while (*splitPtr != '\0'
                   && (*splitPtr != '!' || (splitPtr[-1] == '\\' && splitPtr[-2] != '\\')))
                splitPtr++;
            if (!splitPtr)
                cerr << "Error reading param " << i << " name" << endl;
            *splitPtr = '\0'; // terminate name
            splitPtr++;
            unMask((char *)d_param[i].name); // cast away const - ok here

            /// read type
            d_param[i].type = splitPtr;
            while (*splitPtr && *splitPtr != '!')
                splitPtr++;
            if (!splitPtr)
                cerr << "Error reading param " << i << " type" << endl;
            *splitPtr = '\0'; // terminate type
            splitPtr++;
            unMask((char *)d_param[i].type); // cast away const - ok here

            /// read value
            d_param[i].value = splitPtr;
            while (*splitPtr && *splitPtr != '!')
                splitPtr++;
            if (!splitPtr)
                cerr << "Error reading param " << i << " type" << endl;
            *splitPtr = '\0'; // terminate type
            splitPtr++;
            unMask((char *)d_param[i].value); // cast away const - ok here
        }

        ////// Read User strings
        for (i = 0; i < d_numUser; i++)
        {
            //// read name
            d_user[i] = splitPtr;
            while (*splitPtr != '\0'
                   && (*splitPtr != '!' || (splitPtr[-1] == '\\' && splitPtr[-2] != '\\')))
                splitPtr++;
            if (!splitPtr)
                cerr << "Error reading param " << i << " name" << endl;
            *splitPtr = '\0'; // terminate name
            splitPtr++;
            unMask(d_user[i]);
        }

#ifdef VERBOSE
        fprintf(stderr, "\n    ++++++++++++++++++++++++++++++++++++++++++++++++");
        fprintf(stderr, "\n    ++++       Feedback argument analysis ");
        fprintf(stderr, "\n    ++++++++++++++++++++++++++++++++++++++++++++++++");
        fprintf(stderr, "\n    ++++");
        fprintf(stderr, "\n    ++++ d_numPara    = %d", d_numPara);
        fprintf(stderr, "\n    ++++ d_numUser    = %d", d_numUser);
        fprintf(stderr, "\n    ++++ d_pluginName = %s", d_pluginName);
        fprintf(stderr, "\n    ++++ d_infoString = %s", d_infoString);
        fprintf(stderr, "\n    ++++");
        fprintf(stderr, "\n    ++++++++++++++++++++++++++++++++++++++++++++++++");
        fprintf(stderr, "\n    ++++ Parameters:");
        fprintf(stderr, "\n    ++++");
        for (i = 0; i < d_numPara; i++)
            fprintf(stderr, "\n    ++++ %3d: %15s %7s %s", i, d_param[i].name,
                    d_param[i].type, d_param[i].value);
        fprintf(stderr, "\n    ++++");
        fprintf(stderr, "\n    ++++++++++++++++++++++++++++++++++++++++++++++++");
        fprintf(stderr, "\n    ++++ User strings:");
        fprintf(stderr, "\n    ++++");
        for (i = 0; i < d_numUser; i++)
            fprintf(stderr, "\n    ++++ %3d: %s", i, d_user[i]);
        fprintf(stderr, "\n    ++++");
        fprintf(stderr, "\n    ++++++++++++++++++++++++++++++++++++++++++++++++\n\n");
#endif
    }
}

// un-mask: always skip '\' chars and take over next char
void coBaseCoviseInteractor::unMask(char *string)
{
    char *oPtr = string;
    while (*oPtr)
    {
        if (*oPtr == '\\')
        {
            oPtr++;
            continue;
        }
        if (*oPtr == 127)
            *oPtr = ' ';
        *string = *oPtr;
        string++;
        oPtr++;
    }
}

coBaseCoviseInteractor::~coBaseCoviseInteractor()
{
    delete[] d_infoString;
    delete[] d_feedbackInfo;
    delete[] d_objName;
    delete[] d_pluginName;
    delete[] d_moduleName;
    delete[] d_moduleHost;
    delete[] d_splitString;
}

void coBaseCoviseInteractor::executeModule()
{
    // only the master should fire events for MultiPC versions
    if (coVRMSController::instance()->isMaster())
    {
        sendFeedback(d_feedbackInfo, "EXEC");
    }
}

void coBaseCoviseInteractor::copyModule()
{
    // only the master should fire events for MultiPC versions
    if (coVRMSController::instance()->isMaster())
    {
        sendFeedback(d_feedbackInfo, "COPY_MODULE");
    }
}

void coBaseCoviseInteractor::copyModuleExec()
{
    // only the master should fire events for MultiPC versions
    if (coVRMSController::instance()->isMaster())
    {
        sendFeedback(d_feedbackInfo, "COPY_MODULE_EXEC");
    }
}

void coBaseCoviseInteractor::deleteModule()
{
    // only the master should fire events for MultiPC versions
    if (coVRMSController::instance()->isMaster())
    {
        sendFeedback(d_feedbackInfo, "DELETE_EXEC");
    }
}

void coBaseCoviseInteractor::setBooleanParam(const char *name, int val)
{
    int size = 1; // final '\0'
    size += 2; // number of params
    size += strlen(name) + 1;
    size += strlen("Boolean") + 1;
    size += 5; // number of parameter tokens
    size += 2;

    char *buf = new char[size];

    sprintf(buf, "%s\nBoolean\n%s", name, ((val) ? "TRUE" : "FALSE"));
    sendFeedback(d_feedbackInfo, "PARAM", buf);
    delete[] buf;
}

void coBaseCoviseInteractor::setVectorParam(const char *name, int numElem, float *field)
{
    char *buf;
    char elemBuf[50]; // big enough for one float
    int i, size;

    size = 1; // final '\0'
    size += 2; // number of params
    size += strlen(name) + 1;
    size += strlen("FloatVector") + 1;
    size += 5; // number of parameter tokens
    for (i = 0; i < numElem; i++)
        size += 50;

    buf = new char[size];

    sprintf(buf, "%s\nFloatVector\n", name);

    for (i = 0; i < numElem; i++)
    {
        if (i > 0)
            strcat(buf, " ");
        sprintf(elemBuf, "%f", field[i]);
        strcat(buf, elemBuf);
    }
    sendFeedback(d_feedbackInfo, "PARAM", buf);

    delete[] buf;
}

void coBaseCoviseInteractor::setVectorParam(const char *name, int numElem, int *field)
{
    char *buf;
    char elemBuf[50]; // big enough for one int
    int i, size;
    size = 1; // final '\0'
    size += 2; // number of params
    size += strlen(name) + 1;
    size += strlen("IntVector") + 1;
    size += 5; // number of parameter tokens
    for (i = 0; i < numElem; i++)
        size += 50;

    buf = new char[size];

    sprintf(buf, "%s\nIntVector\n", name);

    for (i = 0; i < numElem; i++)
    {
        if (i > 0)
            strcat(buf, " ");
        sprintf(elemBuf, "%d", field[i]);
        strcat(buf, elemBuf);
    }

    sendFeedback(d_feedbackInfo, "PARAM", buf);

    delete[] buf;
}

void coBaseCoviseInteractor::setVectorParam(const char *name, float u, float v, float w)
{
    char *buf;
    int size;
    int i;
    size = 1; // final '\0'
    size += 2; // number of params
    size += strlen(name) + 1;
    size += strlen("FloatVector") + 1;
    size += 5; // number of parameter tokens
    for (i = 0; i < 3; i++)
        size += 50;

    buf = new char[size];
    sprintf(buf, "%s\nFloatVector\n%f %f %f", name, u, v, w);
    sendFeedback(d_feedbackInfo, "PARAM", buf);
    delete[] buf;
}

void coBaseCoviseInteractor::setVectorParam(const char *name, int u, int v, int w)
{
    char *buf;
    int size;
    int i;
    size = 1; // final '\0'
    size += 2; // number of params
    size += strlen(name) + 1;
    size += strlen("IntVector") + 1;
    size += 5; // number of parameter tokens
    for (i = 0; i < 3; i++)
        size += 50;

    buf = new char[size];

    sprintf(buf, "%s\nIntVector\n%d %d %d", name, u, v, w);
    sendFeedback(d_feedbackInfo, "PARAM", buf);
    delete[] buf;
}

void coBaseCoviseInteractor::setScalarParam(const char *name, float val)
{
    char *buf;
    int size;

    size = 1; // final '\0'
    size += 2; // number of params
    size += strlen(name) + 1;
    size += strlen("FloatScalar") + 1;
    size += 5; // number of parameter tokens
    size += 15;

    buf = new char[size];
    sprintf(buf, "%s\nFloatScalar\n%f", name, val);
    sendFeedback(d_feedbackInfo, "PARAM", buf);
    delete[] buf;
}

void coBaseCoviseInteractor::setScalarParam(const char *name, int val)
{
    char *buf;
    int size;

    size = 1; // final '\0'
    size += 2; // number of params
    size += strlen(name) + 1;
    size += strlen("IntScalar") + 1;
    size += 5; // number of parameter tokens
    size += 15;

    buf = new char[size];

    sprintf(buf, "%s\nIntScalar\n%d", name, val);
    sendFeedback(d_feedbackInfo, "PARAM", buf);
    delete[] buf;
}

void coBaseCoviseInteractor::setSliderParam(const char *name, float min, float max, float value)
{
    char *buf;
    int size;
    size = 1; // final '\0'
    size += 2; // number of params
    size += strlen(name) + 1;
    size += strlen("FloatSlider") + 1;
    size += 5; // number of parameter tokens
    size += 15; // min
    size += 15; // max
    size += 15; // val
    buf = new char[size];

    sprintf(buf, "%s\nFloatSlider\n%f %f %f", name, min, max, value);
    sendFeedback(d_feedbackInfo, "PARAM", buf);
    delete[] buf;
}

void coBaseCoviseInteractor::setSliderParam(const char *name, int min, int max, int value)
{
    char *buf;
    int size;
    size = 1; // final '\0'
    size += 2; // number of params
    size += strlen(name) + 1;
    size += strlen("IntSlider") + 1;
    size += 5; // number of parameter tokens
    size += 15; // min
    size += 15; // max
    size += 15; // val
    buf = new char[size];

    sprintf(buf, "%s\nIntSlider\n%d %d %d", name, min, max, value);
    sendFeedback(d_feedbackInfo, "PARAM", buf);
    delete[] buf;
}

void coBaseCoviseInteractor::setStringParam(const char *name, const char *val)
{
    char *buf;
    int size;

    size = 1; // final '\0'
    size += 2; // number of params
    size += strlen(name) + 1;
    size += strlen("String") + 1;
    size += 5; // number of parameter tokens
    size += strlen(val) + 1;
    buf = new char[size];

    sprintf(buf, "%s\nString\n%s", name, val);
    sendFeedback(d_feedbackInfo, "PARAM", buf);
    delete[] buf;
}

void coBaseCoviseInteractor::setFileBrowserParam(const char *name, const char *val)
{
    char *buf;
    int size;

    size = 1; // final '\0'
    size += 2; // number of params
    size += strlen(name) + 1;
    size += strlen("Browser") + 1;
    size += 5; // number of parameter tokens
    size += strlen(val) + 1;
    buf = new char[size];

    sprintf(buf, "%s\nBrowser\n%s", name, val);
    sendFeedback(d_feedbackInfo, "PARAM", buf);
    delete[] buf;
}

void coBaseCoviseInteractor::setChoiceParam(const char *name, int num, const char *const *list, int pos)
{
    char *buf;
    int i, size;

    size = 1; // final '\0'
    size += 2; // number of params
    size += strlen(name) + 1;
    size += strlen("Choice") + 1;
    size += 5; // number of parameter tokens
    size += 5; // num of selections
    size += 5; // selected pos
    for (i = 0; i < num; i++)
        size += strlen(list[i]) + 2;

    buf = new char[size]; // see ApplInterface.cpp CoviseRender::update_choice_param

    sprintf(buf, "%s\nChoice\n%d ", name, pos + 1);
    for (i = 0; i < num; i++)
    {
        char *p = buf + strlen(buf);
        strcat(buf, list[i]);
        while (*p)
        {
            if (*p == ' ')
                *p = '\177';
            ++p;
        }
        char *lastChar = &buf[strlen(buf) - 1];
        if (*lastChar == '\n' || *lastChar == ' ')
            *lastChar = ' ';
        else
            strcat(buf, " ");
    }
    sendFeedback(d_feedbackInfo, "PARAM", buf);
    delete[] buf;
}

// ---------------------------------------------------------------------------
// aw: get-functions for all types

int coBaseCoviseInteractor::getBooleanParam(const std::string &paraName, int &value) const
{
    for (unsigned int ctr = 0; ctr < d_numPara; ++ctr)
    {
        if (paraName == getParaName(ctr))
            return getBooleanParam(ctr, value);
    }
    return -1;
}

int coBaseCoviseInteractor::getIntScalarParam(const std::string &paraName, int &value) const
{
    for (unsigned int ctr = 0; ctr < d_numPara; ++ctr)
    {
        if (paraName == getParaName(ctr))
            return getIntScalarParam(ctr, value);
    }
    return -1;
}

int coBaseCoviseInteractor::getFloatScalarParam(const std::string &paraName, float &value) const
{
    for (unsigned int ctr = 0; ctr < d_numPara; ++ctr)
    {
        if (paraName == getParaName(ctr))
            return getFloatScalarParam(ctr, value);
    }
    return -1;
}

int coBaseCoviseInteractor::getIntSliderParam(const std::string &paraName, int &min, int &max, int &val) const
{
    for (unsigned int ctr = 0; ctr < d_numPara; ++ctr)
    {
        if (paraName == getParaName(ctr))
            return getIntSliderParam(ctr, min, max, val);
    }
    return -1;
}

int coBaseCoviseInteractor::getFloatSliderParam(const std::string &paraName, float &min, float &max, float &val) const
{
    for (unsigned int ctr = 0; ctr < d_numPara; ++ctr)
    {
        if (paraName == getParaName(ctr))
            return getFloatSliderParam(ctr, min, max, val);
    }
    return -1;
}

int coBaseCoviseInteractor::getIntVectorParam(const std::string &paraName, int &numElem, int *&val) const
{
    for (unsigned int ctr = 0; ctr < d_numPara; ++ctr)
    {
        if (paraName == getParaName(ctr))
            return getIntVectorParam(ctr, numElem, val);
    }
    return -1;
}

int coBaseCoviseInteractor::getFloatVectorParam(const std::string &paraName, int &numElem, float *&val) const
{
    for (unsigned int ctr = 0; ctr < d_numPara; ++ctr)
    {
        if (paraName == getParaName(ctr))
            return getFloatVectorParam(ctr, numElem, val);
    }
    return -1;
}

int coBaseCoviseInteractor::getStringParam(const std::string &paraName, const char *&val) const
{
    for (unsigned int ctr = 0; ctr < d_numPara; ++ctr)
    {
        if (paraName == getParaName(ctr))
            return getStringParam(ctr, val);
    }
    return -1;
}

int coBaseCoviseInteractor::getChoiceParam(const std::string &paraName, int &num, char **&labels, int &active) const
{
    for (unsigned int ctr = 0; ctr < d_numPara; ++ctr)
    {
        if (paraName == getParaName(ctr))
            return getChoiceParam(ctr, num, labels, active);
    }
    return -1;
}

int coBaseCoviseInteractor::getFileBrowserParam(const std::string &paraName, char *&val) const
{
    for (unsigned int ctr = 0; ctr < d_numPara; ++ctr)
    {
        if (paraName == getParaName(ctr))
            return getFileBrowserParam(ctr, val);
    }
    return -1;
}

int coBaseCoviseInteractor::getBooleanParam(unsigned int paraNo, int &value) const
{
    if (paraNo >= d_numPara
        || !d_param[paraNo].value || strcmp(d_param[paraNo].type, "BOOL"))
        return -1;

    const char *str = d_param[paraNo].value;
    value = (str && (*str == 't' || *str == 'T' || *str == '1'));

    return 0;
}

int coBaseCoviseInteractor::getIntScalarParam(unsigned int paraNo, int &value) const
{
    if (paraNo >= d_numPara
        || !d_param[paraNo].value || strcmp(d_param[paraNo].type, "INTSCA"))
        return -1;

    if (1 != sscanf(d_param[paraNo].value, "%d", &value))
        return -1;
    else
        return 0;
}

int coBaseCoviseInteractor::getFloatScalarParam(unsigned int paraNo, float &value) const
{
    if (paraNo >= d_numPara
        || !d_param[paraNo].value || strcmp(d_param[paraNo].type, "FLOSCA"))
        return -1;

    if (1 != sscanf(d_param[paraNo].value, "%f", &value))
        return -1;
    else
        return 0;
}

int coBaseCoviseInteractor::getIntSliderParam(unsigned int paraNo, int &min, int &max, int &val) const
{
    if (paraNo >= d_numPara
        || !d_param[paraNo].value || strcmp(d_param[paraNo].type, "INTSLI"))
        return -1;

    if (3 != sscanf(d_param[paraNo].value, "%d %d %d", &min, &max, &val))
        return -1;
    else
        return 0;
}

int coBaseCoviseInteractor::getFloatSliderParam(unsigned int paraNo, float &min, float &max, float &val) const
{
    if (paraNo >= d_numPara
        || !d_param[paraNo].value || strcmp(d_param[paraNo].type, "FLOSLI"))
        return -1;

    if (3 != sscanf(d_param[paraNo].value, "%f %f %f", &min, &max, &val))
        return -1;
    else
        return 0;
}

// skip all blanks or tilll end, return ref to active char
inline const char &skipSpace(const char *&str)
{
    while (*str && isspace(*str))
        str++;
    return *str;
}

// skip all non-blanks or tilll end, return ref to active char
inline const char &skipNonSpace(const char *&str)
{
    while (*str && !isspace(*str))
        str++;
    return *str;
}

int coBaseCoviseInteractor::getIntVectorParam(unsigned int paraNo, int &numElem, int *&val) const
{
    if (paraNo >= d_numPara
        || !d_param[paraNo].value || strcmp(d_param[paraNo].type, "INTVEC"))
        return -1;

    const char *str = d_param[paraNo].value;

    if (!skipSpace(str))
        return -1; // skip leading blanks, return if end

    // get first number: number of elements
    if (1 != sscanf(str, "%d", &numElem))
        return -1;
    val = new int[numElem];

    if (!skipNonSpace(str))
        return -1; // skip to next blank return if end

    int i;
    for (i = 0; i < numElem; i++)
    {
        if (!skipSpace(str))
            return -1; // skip leading blanks, return if end
        if (sscanf(str, "%d", &val[i]) != 1) // read one number
        {
            cerr << "coBaseCoviseInteractor::getIntVectorParam: sscanf failed" << endl;
        }
        if (!skipNonSpace(str))
            return -1; // skip to next blank, return if end
    }
    return 0;
}

int coBaseCoviseInteractor::getFloatVectorParam(unsigned int paraNo, int &numElem, float *&val) const
{
    if (paraNo >= d_numPara
        || !d_param[paraNo].value || strcmp(d_param[paraNo].type, "FLOVEC"))
        return -1;

    const char *str = d_param[paraNo].value;

    if (!skipSpace(str))
        return -1; // skip leading blanks, return if end

    // get first number: number of elements
    if (1 != sscanf(str, "%d", &numElem))
        return -1;
    val = new float[numElem];

    if (!skipNonSpace(str))
        return -1; // skip to next blank return if end

    int i;
    for (i = 0; i < numElem; i++)
    {
        if (!skipSpace(str))
            return -1; // skip leading blanks, return if end
        if (sscanf(str, "%f", &val[i]) != 1) // read one number
        {
            cerr << "coBaseCoviseInteractor::getFloatVectorParam: sscanf failed" << endl;
        }
        if (!skipNonSpace(str))
            return -1; // skip to next blank, return if end
    }
    return 0;
}

int coBaseCoviseInteractor::getStringParam(unsigned int paraNo, const char *&val) const
{
    if (paraNo >= d_numPara
        || !d_param[paraNo].value || strcmp(d_param[paraNo].type, "STRING"))
        return -1;

    const char *str = d_param[paraNo].value;
    char *value = new char[strlen(str) + 1];
    strcpy(value, str);
    unMask(value);
    val = value;

    return 0;
}

int coBaseCoviseInteractor::getFileBrowserParam(unsigned int paraNo, char *&val) const
{
    if (paraNo >= d_numPara
        || !d_param[paraNo].value || strcmp(d_param[paraNo].type, "BROWSE"))
        return -1;

    const char *str = d_param[paraNo].value;
    val = new char[strlen(str) + 1];
    strcpy(val, str);
    unMask(val);

    return 0;
}

int coBaseCoviseInteractor::getChoiceParam(unsigned int paraNo, int &num, char **&labels, int &active) const
{
    if (paraNo >= d_numPara
        || !d_param[paraNo].value || strcmp(d_param[paraNo].type, "CHOICE"))
        return -1;

    const char *str = d_param[paraNo].value;
    int i;
    if (2 != sscanf(str, "%d %d", &num, &active))
        return -1;

    if (num == 0) // empty choice
    {
        active = 0;
        labels = NULL;
        return 0;
    }

    active--;

    //skip to first '$' (cannot be a masked one)
    while (*str && *str != '$')
        str++;
    if (!str)
        return -1;

    // allocate choice label array
    labels = new char *[num];

    for (i = 0; i < num; i++)
    {
        // skip leading '$'
        str++;

        // find end and count elements
        const char *ePtr = str;
        int len = 0;
        while (*ePtr && (*ePtr != '$'
                         || (ePtr[-1] == '\\' && ePtr[-2] != '\\')))
        {
            len++;
            ePtr++;
        }
        labels[i] = new char[len + 1];
        char *dPtr = labels[i];
        while (str != ePtr)
        {
            *dPtr = *str;
            dPtr++;
            str++;
        }
        *dPtr = '\0';
    }

    for (i = 0; i < num; i++)
        unMask(labels[i]);

    return 0;
}

// ---------------------------------------------------------------------------

void coBaseCoviseInteractor::print(FILE *outfile)
{
    unsigned int i;
    char *feedStr = new char[strlen(d_feedbackInfo) * 2 + 1];
    feedStr[0] = '\0';
    char add[2];
    add[1] = '\0';
    const char *nl = "\\n";

    for (i = 0; i < strlen(d_feedbackInfo); i++)
    {
        if (d_feedbackInfo[i] == '\n')
        {
            strcat(feedStr, nl);
        }
        else
        {
            add[0] = d_feedbackInfo[i];
            strcat(feedStr, add);
        }
    }

    fprintf(outfile, "\n    ++++++++++++++++++++++++++++++++++++++++++++++++");
    fprintf(outfile, "\n    ++++       Feedback argument analysis ");
    fprintf(outfile, "\n    ++++++++++++++++++++++++++++++++++++++++++++++++");
    fprintf(outfile, "\n    ++++");
    fprintf(outfile, "\n    ++++ d_feedbackInfo = %p", feedStr);
    fprintf(outfile, "\n    ++++ d_numPara      = %d", d_numPara);
    fprintf(outfile, "\n    ++++ d_numUser      = %d", d_numUser);
    fprintf(outfile, "\n    ++++ d_pluginName   = %s", d_pluginName);
    fprintf(outfile, "\n    ++++ d_infoString   = %s", d_infoString);
    fprintf(outfile, "\n    ++++ d_refCount     = %d", d_refCount);
    fprintf(outfile, "\n    ++++ d_moduleName      = %s", d_moduleName);
    fprintf(outfile, "\n    ++++ d_moduleHost      = %s", d_moduleHost);
    fprintf(outfile, "\n    ++++ d_moduleInstance      = %d", d_moduleInstance);
    fprintf(outfile, "\n    ++++");
    fprintf(outfile, "\n    ++++++++++++++++++++++++++++++++++++++++++++++++");
    fprintf(outfile, "\n    ++++ Parameters:");
    fprintf(outfile, "\n    ++++");
    for (i = 0; i < d_numPara; i++)
        fprintf(outfile, "\n    ++++ %3d: %15s %7s %s", i, d_param[i].name,
                d_param[i].type, d_param[i].value);
    fprintf(outfile, "\n    ++++");
    fprintf(outfile, "\n    ++++++++++++++++++++++++++++++++++++++++++++++++");
    fprintf(outfile, "\n    ++++ User strings:");
    fprintf(outfile, "\n    ++++");
    for (i = 0; i < d_numUser; i++)
        fprintf(outfile, "\n    ++++ %3d: %s", i, d_user[i]);
    fprintf(outfile, "\n    ++++");
    fprintf(outfile, "\n    ++++++++++++++++++++++++++++++++++++++++++++++++\n\n");

    delete[] feedStr;
}

// get a parameter record: use interact->para(1)->name et al.
const coBaseCoviseInteractor::paraRec *coBaseCoviseInteractor::getPara(unsigned int i) const
{
    if (i < d_numPara)
        return &d_param[i];
    else
        return &d_param[d_numPara]; // the 'bad' element
}

// get a parameter record: use interact->para(1)->name et al.
const char *coBaseCoviseInteractor::getParaName(unsigned int i) const
{
    if (i < d_numPara)
        return d_param[i].name;
    else
        return d_param[d_numPara].name; // the 'bad' element
}

// get a parameter name
const char *coBaseCoviseInteractor::getParaType(unsigned int i) const
{
    if (i < d_numPara)
        return d_param[i].type;
    else
        return d_param[d_numPara].type; // the 'bad' element
}

// get a parameter name
const char *coBaseCoviseInteractor::getParaValue(unsigned int i) const
{
    if (i < d_numPara)
        return d_param[i].value;
    else
        return d_param[d_numPara].value; // the 'bad' element
}

// get a parameter type
const char *coBaseCoviseInteractor::getString(unsigned int i) const
{
    if (i < d_numUser)
        return d_user[i];
    else
        return d_user[d_numUser]; // the 'bad' element
}