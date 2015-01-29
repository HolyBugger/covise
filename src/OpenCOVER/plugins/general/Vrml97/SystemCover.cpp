/* This file is part of COVISE.

   You can use it under the terms of the GNU Lesser General Public License
   version 2.1 or later, see lgpl-2.1.txt.

 * License: LGPL 2+ */

//
//  Vrml 97 library
//  Copyright (C) 1998 Chris Morley
//
//  SystemCover.cpp
//  A class to contain system-dependent/non-standard utilities
//
#ifdef WIN32
#ifdef WIN32_LEAN_AND_MEAN
#undef WIN32_LEAN_AND_MEAN
#endif
#include <winsock2.h>
#include <Windows.h>
#endif

#include <util/common.h>
#include <fcntl.h>
#include <vrml97/vrml/config.h>
#include <vrml97/vrml/System.h>

#include <vrml97/vrml/VrmlScene.h>
#include <vrml97/vrml/VrmlSFBool.h>
#include <vrml97/vrml/VrmlNodeViewpoint.h>
#include <config/CoviseConfig.h>
#include <cover/coVRPluginSupport.h>
#include <cover/input/input.h>
#include <cover/coVRConfig.h>
#include <cover/coVRMSController.h>
#include <cover/coVRCommunication.h>
#include <cover/coVRAnimationManager.h>
#include <cover/coVRCollaboration.h>
#include <cover/coVRNavigationManager.h>
#include <cover/coVRFileManager.h>
#include <cover/VRSceneGraph.h>
#include <cover/OpenCOVER.h>
#include <cover/VRAvatar.h>
#include <net/message.h>
#include <net/message_types.h>
#include <vrbclient/VRBClient.h>
#include <vrbclient/VRBMessage.h>

#include <cover/coVRLighting.h>
#include "cover/coVRTui.h"
#include <OpenVRUI/coCheckboxMenuItem.h>
#include <OpenVRUI/coButtonMenuItem.h>
#include <OpenVRUI/coSubMenuItem.h>
#include <OpenVRUI/coRowMenu.h>
#include <OpenVRUI/coCheckboxGroup.h>
#include <OpenVRUI/coButtonMenuItem.h>

#include "SystemCover.h"
#include "ViewerObject.h"
#include "ViewerOsg.h"
#include "Vrml97Plugin.h"

#ifdef _WIN32
#include <fcntl.h>
#include <exdisp.h>
#ifndef MINGW
#include <atlbase.h>
#include "atlconv.h"
#endif
#endif

#include <osg/MatrixTransform>
#include <osgDB/Registry>
#include <osgDB/ReadFile>
#include <osgDB/WriteFile>
#include <osgDB/FileNameUtils>
#include <osgDB/ReaderWriter>
#include <osgUtil/Optimizer>

using namespace covise;

ViewpointEntry::ViewpointEntry(VrmlNodeViewpoint *aViewPoint, VrmlScene *aScene)
    : menuItem(NULL)
{
    scene = aScene;
    viewPoint = aViewPoint;
    entryNumber = ((SystemCover *)System::the)->maxEntryNumber++;

    tuiItem = new coTUIToggleButton(viewPoint->description(), ((SystemCover *)System::the)->vrmlTab->getID());
    tuiItem->setEventListener((SystemCover *)System::the);
    tuiItem->setPos((int)(entryNumber / 10.0) + 1, entryNumber % 10);
}

ViewpointEntry::~ViewpointEntry()
{
    delete menuItem;
}

void ViewpointEntry::setMenuItem(coCheckboxMenuItem *aButton)
{
    menuItem = aButton;
}

void ViewpointEntry::activate()
{
    double timeNow = System::the->time();
    VrmlSFBool flag(true);
    viewPoint->eventIn(timeNow, "set_bind", &flag);
}

void ViewpointEntry::menuEvent(coMenuItem *aButton)
{
    if (((coCheckboxMenuItem *)aButton)->getState())
    {
        activate();
    }
}

SystemCover::SystemCover()
{
    mFileManager = coVRFileManager::instance();
    maxEntryNumber = 0;
    record = false;
    fileNumber = 0;
}
bool SystemCover::loadUrl(const char *url, int np, char **parameters)
{
    if (!url)
        return false;
    char *buf = new char[strlen(url) + 200];
    int result = 1;
#if !defined(_WIN32) || defined(MINGW)
    if (np)
        sprintf(buf, "/bin/csh -c \"netscape -remote 'openURL(%s, %s)'\" &",
                url, parameters[0]);
    else
        sprintf(buf, "/bin/csh -c \"netscape -remote 'openURL(%s)'\" &", url);
    result = system(buf);
    fprintf(stderr, "%s\n", buf);
#else
    ::CoInitialize(NULL);
    static IWebBrowser2 *browser = NULL;

    if (browser == NULL)
    {
        HRESULT hRes = CoCreateInstance(CLSID_InternetExplorer, NULL, CLSCTX_LOCAL_SERVER,
                                        IID_IWebBrowser2, (void **)&browser);
        if (FAILED(hRes))
        {
            return false;
        }
    }

    {
        VARIANT vEmpty;
        VariantInit(&vEmpty);

        //UpdateData(TRUE);

        USES_CONVERSION;
        BSTR bstrURL = SysAllocString(A2OLE((const char *)url));

        HRESULT hr = browser->Navigate(bstrURL, &vEmpty, &vEmpty, &vEmpty, &vEmpty);
        if (SUCCEEDED(hr))
        {
            browser->put_Visible(VARIANT_TRUE);
        }
        else
        {
            browser->Quit();
        }

        SysFreeString(bstrURL);
        //browser->Release();
        //browser = NULL;
    }
/*if (np)
   {
  ShellExecute(NULL, "open", url,
                parameters[0], NULL, SW_SHOWNORMAL);
   }
   else
   {
  ShellExecute(NULL, "open", url,
                NULL, NULL, SW_SHOWNORMAL);
   }*/
#endif

    delete[] buf;
    return (result >= 0); // _WIN32
}

void SystemCover::createMenu()
{

    cbg = new coCheckboxGroup();
    viewpointMenu = new coRowMenu("VRML Viewpoints");

    VRMLButton = new coSubMenuItem("VRML");
    VRMLButton->setMenu(viewpointMenu);

    addVPButton = new coButtonMenuItem("SaveViewpoint");
    addVPButton->setMenuListener(this);
    viewpointMenu->add(addVPButton);
    reloadButton = new coButtonMenuItem("Reload");
    reloadButton->setMenuListener(this);
    viewpointMenu->add(reloadButton);

    cover->getMenu()->add(VRMLButton);

    vrmlTab = new coTUITab("Vrml97", coVRTui::instance()->mainFolder->getID());
    vrmlTab->setPos(0, 0);

    reload = new coTUIButton("Reload", vrmlTab->getID());
    reload->setEventListener(this);
    reload->setPos(0, 0);

    saveViewpoint = new coTUIButton("Save Viewpoint", vrmlTab->getID());
    saveViewpoint->setEventListener(this);
    saveViewpoint->setPos(0, 1);

    saveAnimation = new coTUIToggleButton("Save Animation", vrmlTab->getID());
    saveAnimation->setEventListener(this);
    saveAnimation->setPos(0, 2);
}

void SystemCover::menuEvent(coMenuItem *aButton)
{
    if (aButton == reloadButton)
    {
        coVRFileManager::instance()->reloadFile();
    }
    if (aButton == addVPButton)
    {
        printViewpoint();
    }
}
// reload has been moved to tabletPressEvent because it causes a destruction of
// the vrml menu and thus the TUI Item and this causes a crash when
// tabletPressEvent is called after tabletEvent and the menu item is no longer
// valid.
// nothing else is done after tabletPressEvent thus we should be safe.
void SystemCover::tabletPressEvent(coTUIElement *tUIItem)
{
    if (tUIItem == reload)
    {
        coVRFileManager::instance()->reloadFile();
    }
}

void SystemCover::tabletEvent(coTUIElement *tUIItem)
{
    if (tUIItem == saveViewpoint)
    {
        printViewpoint();
    }
    else if (tUIItem == saveAnimation)
    {
        if (saveAnimation->getState())
            startCapture();
        else
            stopCapture();
    }
    else
    {
        for (list<ViewpointEntry *>::iterator it = viewpointEntries.begin();
             it != viewpointEntries.end(); it++)
        {
            if ((*it)->getTUIItem() == tUIItem)
            {
                (*it)->activate();
                break;
            }
        }
    }
}
#define INTERVAL 0.5
void SystemCover::update()
{
    System::update();
    if (record)
    {
        static double oldTime = 0;
        double time = cover->frameTime();
        if (time - oldTime > INTERVAL)
        {
            oldTime = time;
            osg::Matrix mat = cover->getXformMat();
            osg::Matrix rotMat;

            rotMat.makeRotate(M_PI / 2.0, osg::Vec3(1.0, 0.0, 0.0));
            mat.preMult(rotMat);
            rotMat.makeRotate(-M_PI / 2.0, osg::Vec3(1.0, 0.0, 0.0));
            mat.postMult(rotMat);

            osg::Quat q;
            q.set(mat);
            osg::Quat::value_type orient[4];
            q.getRotate(orient[3], orient[0], orient[1], orient[2]);
            rotMat.makeRotate(-orient[3], orient[0], orient[1], orient[2]);
            mat.postMult(rotMat);
            osg::Vec3 Trans = mat.getTrans();

            positions[frameNumber * 3] = Trans[0] / (-cover->getScale());
            positions[frameNumber * 3 + 1] = Trans[1] / (-cover->getScale());
            positions[frameNumber * 3 + 2] = Trans[2] / (-cover->getScale());
            orientations[frameNumber * 4] = orient[0];
            orientations[frameNumber * 4 + 1] = orient[1];
            orientations[frameNumber * 4 + 2] = orient[2];
            orientations[frameNumber * 4 + 3] = -orient[3];
            frameNumber++;
            if (frameNumber >= 1200)
            {
                stopCapture();
            }
        }
    }
}

void SystemCover::startCapture()
{
    if (record)
    {
        stopCapture();
    }
    char fileName[100];
    sprintf(fileName, "Animation.wrl");
    fileNumber++;
    frameNumber = 0;
    fp = fopen(fileName, "a+");
    positions = new float[3 * 1202];
    orientations = new float[4 * 1202];
    if (fp)
    {
        record = true;
    }
    else
        perror("Animation.wrl");
}
void SystemCover::stopCapture()
{
    if (!record)
    {
        return;
    }
    fprintf(fp, "#VRML V2.0 utf8\n\nDEF Camera%d Viewpoint {  \nposition %f %f %f\n  orientation %f %f %f %f\n  fieldOfView 0.6024 description \"Camera%d\"\n}\n", fileNumber, positions[0], positions[1], positions[2], orientations[0], orientations[1], orientations[2], orientations[3], fileNumber);
    fprintf(fp, "DEF Camera%d-TIMER TimeSensor { loop TRUE cycleInterval %f }\n", fileNumber, frameNumber * INTERVAL);
    fprintf(fp, "DEF Camera%d-POS-INTERP PositionInterpolator {\n key [\n", fileNumber);
    int i = 0;
    int z = 0;
    for (i = 0; i < frameNumber; i++)
    {
        fprintf(fp, " %f,", (float)i / (frameNumber - 1));
        z++;
        if (z > 10)
        {
            z = 0;
            fprintf(fp, "\n");
        }
    }
    fprintf(fp, "]\nkeyValue [\n");

    for (i = 0; i < frameNumber; i++)
    {
        fprintf(fp, " %f %f %f,", positions[i * 3], positions[i * 3 + 1], positions[i * 3 + 2]);
        z++;
        if (z > 3)
        {
            z = 0;
            fprintf(fp, "\n");
        }
    }

    fprintf(fp, "] }\n");

    fprintf(fp, "DEF Camera%d-ROT-INTERP OrientationInterpolator {\n key [\n", fileNumber);
    for (i = 0; i < frameNumber; i++)
    {
        fprintf(fp, " %f,", (float)i / (frameNumber - 1));
        z++;
        if (z > 10)
        {
            z = 0;
            fprintf(fp, "\n");
        }
    }
    fprintf(fp, "]\nkeyValue [\n");

    for (i = 0; i < frameNumber; i++)
    {
        fprintf(fp, " %f %f %f %f,", orientations[i * 4], orientations[i * 4 + 1], orientations[i * 4 + 2], orientations[i * 4 + 3]);
        z++;
        if (z > 3)
        {
            z = 0;
            fprintf(fp, "\n");
        }
    }

    fprintf(fp, "] }\n");
    fprintf(fp, "ROUTE Camera%d-TIMER.fraction_changed TO Camera%d-POS-INTERP.set_fraction\n", fileNumber, fileNumber);
    fprintf(fp, "ROUTE Camera%d-POS-INTERP.value_changed TO Camera%d.set_position\n", fileNumber, fileNumber);
    fprintf(fp, "ROUTE Camera%d-TIMER.fraction_changed TO Camera%d-ROT-INTERP.set_fraction\n", fileNumber, fileNumber);
    fprintf(fp, "ROUTE Camera%d-ROT-INTERP.value_changed TO Camera%d.set_orientation\n", fileNumber, fileNumber);

    fclose(fp);
    record = false;
    delete[] positions;
    delete[] orientations;
}

void SystemCover::printViewpoint()
{
    //write vrml Viewpoint
    // only write VRML viewpoints if VRML_WRITE_VIEWPOINTS is set

    osg::Matrix mat = cover->getXformMat();
    osg::Matrix rotMat;

    rotMat.makeRotate(M_PI / 2.0, osg::Vec3(1.0, 0.0, 0.0));
    mat.preMult(rotMat);
    rotMat.makeRotate(-M_PI / 2.0, osg::Vec3(1.0, 0.0, 0.0));
    mat.postMult(rotMat);

    osg::Quat q;
    q.set(mat);
    osg::Quat::value_type orient[4];
    q.getRotate(orient[3], orient[0], orient[1], orient[2]);
    rotMat.makeRotate(-orient[3], orient[0], orient[1], orient[2]);
    mat.postMult(rotMat);
    osg::Vec3 Trans = mat.getTrans();

    fprintf(stderr, "\nDEF Camera6 Viewpoint\n");
    fprintf(stderr, "{\n");
    fprintf(stderr, "position %f %f %f \n", Trans[0] / (-cover->getScale()), Trans[1] / (-cover->getScale()), Trans[2] / (-cover->getScale()));
    fprintf(stderr, "orientation %f %f %f %f\n", orient[0], orient[1], orient[2], -orient[3]);
    fprintf(stderr, "description \"NoName\"\n");
    fprintf(stderr, "type \"Free\"\n");
    fprintf(stderr, "}\n");
    fprintf(stderr, "\nscale %f\n", cover->getScale());

    rotMat.makeRotate(M_PI / 2.0, osg::Vec3(1.0, 0.0, 0.0));
    mat.postMult(rotMat);
    Trans = mat.getTrans();
    rotMat.makeRotate(-orient[3], orient[0], orient[1], orient[2]);
    mat.postMult(rotMat);

    q.set(mat);
    q.getRotate(orient[3], orient[0], orient[1], orient[2]);
    cerr << endl << "3DSmax Camera:" << endl;
    fprintf(stderr, "position %f %f %f \n", Trans[0] / (-cover->getScale()), Trans[1] / (-cover->getScale()), Trans[2] / (-cover->getScale()));
    fprintf(stderr, "orientation %f %f %f %f\n", orient[0], orient[1], orient[2], -orient[3] / M_PI * 180);
    fprintf(stderr, "matrix3 [ %f, %f, %f ] [ %f, %f, %f ] [ %f, %f, %f ] [ %f, %f, %f ] \n", mat(0, 0), mat(0, 1), mat(0, 2), mat(1, 0), mat(1, 1), mat(1, 2), mat(2, 0), mat(2, 1), mat(2, 2), Trans[0] / (-cover->getScale()), Trans[1] / (-cover->getScale()), Trans[2] / (-cover->getScale()));
}

void SystemCover::destroyMenu()
{
    //coMenu *menu = cover->getMenu();
    //menu->remove(VRMLButton);
    delete viewpointMenu;
    delete VRMLButton;
    delete cbg;

    delete saveAnimation;
    delete saveViewpoint;
    delete reload;
    delete vrmlTab;
}

double SystemCover::time()
{
    return cover->frameTime();
}

//TODO: Add distinction for vrb files here. filename is always an url.
//      Return the path to the file in local temp dir.
//      --> Handle vrb:// and agtk3://
//      Also add file:// path substition here?
const char *SystemCover::remoteFetch(const char *filename)
{
    char *result = 0;
    const char *buf = NULL;
    int numBytes = 0;
    static int working = 0;

    if (working)
    {
        cerr << "WARNING!!! reentered remoteFetch!!!!" << endl;
        return NULL;
    }

    working = 1;

    if (strncmp(filename, "vrb://", 6) == 0)
    {
        //Request file from VRB
        std::cerr << "VRB file, needs to be requested through FileBrowser-ProtocolHandler!" << std::endl;
        coTUIFileBrowserButton *locFB = this->mFileManager->getMatchingFileBrowserInstance(string(filename));
        std::string sresult = locFB->getFilename(filename).c_str();
        char *result = new char[sresult.size() + 1];
        strcpy(result, sresult.c_str());
        working = 0;
        return result;
    }
    else if (strncmp(filename, "agtk3://", 8) == 0)
    {
        //REquest file from AG data store
        std::cerr << "AccessGrid file, needs to be requested through FileBrowser-ProtocolHandler!" << std::endl;
        coTUIFileBrowserButton *locFB = this->mFileManager->getMatchingFileBrowserInstance(string(filename));
        working = 0;
        return locFB->getFilename(filename).c_str();
    }

    if (vrbc || !coVRMSController::instance()->isMaster())
    {
        if (coVRMSController::instance()->isMaster())
        {
            TokenBuffer rtb;
            rtb << filename;
            rtb << vrbc->getID();
            Message m(rtb);
            m.type = COVISE_MESSAGE_VRB_REQUEST_FILE;
            vrbc->sendMessage(&m);
        }
        int message = 1;
        Message *msg = new Message;
        do
        {
            if (coVRMSController::instance()->isMaster())
            {
                if (!vrbc->isConnected())
                {
                    message = 0;
                    coVRMSController::instance()->sendSlaves((char *)&message, sizeof(message));
                    break;
                }
                else
                {
                    vrbc->wait(msg);
                }
                coVRMSController::instance()->sendSlaves((char *)&message, sizeof(message));
            }
            if (coVRMSController::instance()->isMaster())
            {
                coVRMSController::instance()->sendSlaves(msg);
            }
            else
            {
                coVRMSController::instance()->readMaster((char *)&message, sizeof(message));
                if (message == 0)
                    break;
                // wait for message from master instead
                coVRMSController::instance()->readMaster(msg);
            }
            coVRCommunication::instance()->handleVRB(msg);
        } while (msg->type != COVISE_MESSAGE_VRB_SEND_FILE);

        if ((msg->data) && (msg->type == COVISE_MESSAGE_VRB_SEND_FILE))
        {
            TokenBuffer tb(msg);
            int myID;
            tb >> myID; // this should be my ID
            tb >> numBytes;
            buf = tb.getBinary(numBytes);
            if ((numBytes > 0) && (result = tempnam(0, "VR")))
            {
#ifndef _WIN32
                int fd = open(result, O_RDWR | O_CREAT, 0777);
#else
                int fd = open(result, O_RDWR | O_CREAT | O_BINARY, 0777);
#endif
                if (fd != -1)
                {
                    if (write(fd, buf, numBytes) != numBytes)
                    {
                        warn("remoteFetch: temp file write error\n");
                        free(result);
                        result = NULL;
                    }
                    close(fd);
                }
                else
                {
                    free(result);
                    result = NULL;
                }
            }
        }
        delete msg;
    }
    working = 0;
    return result;
}

void SystemCover::setSyncMode(const char *mode)
{
    coVRCollaboration::instance()->setSyncMode(mode);
}

bool SystemCover::isMaster()
{
    return coVRCommunication::instance()->isMaster();
}

void SystemCover::becomeMaster()
{
    coVRCommunication::instance()->becomeMaster();
}

void SystemCover::setBuiltInFunctionState(const char *fname, int val)
{
    cover->setBuiltInFunctionState(fname, val);
}

void SystemCover::setBuiltInFunctionValue(const char *fname, float val)
{
    cover->setBuiltInFunctionValue(fname, val);
}

void SystemCover::callBuiltInFunctionCallback(const char *fname)
{
    cover->callBuiltInFunctionCallback(fname);
}

Player *SystemCover::getPlayer()
{
    return NULL;
}

VrmlMessage *SystemCover::newMessage(size_t len)
{
    VrmlMessage *msg = new VrmlMessage(len + sizeof(int));
    int tag = coVRPluginSupport::VRML_EVENT;
    msg->append(tag);

    return msg;
}

void SystemCover::sendAndDeleteMessage(VrmlMessage *msg)
{
    if (msg->pos > msg->size)
    {
        cerr << "SystemCover::sendAndDeleteMessage: msg->pos > msg->size !!!" << endl;
    }

    Message *message = new Message();
    message->data = msg->buf;
    message->type = COVISE_MESSAGE_RENDER_MODULE;
    message->length = msg->size;

    cover->sendVrbMessage(message);

    delete message;
    delete msg;
}

bool SystemCover::hasRemoteConnection()
{
    return coVRCommunication::instance()->collaborative();
}

long SystemCover::getMaxHeapBytes()
{
    long max_heap = coCoviseConfig::getInt("COVER.Plugin.Vrml97.MaxHeapBytes", -1);
    if (max_heap < 2)
        max_heap = -1;
    else if (max_heap > 10000)
        max_heap = -1;
    else
        max_heap *= 1024L * 1024L;
    return max_heap;
}

bool SystemCover::getHeadlight()
{
    return coCoviseConfig::isOn("COVER.Headlight", true);
}

void SystemCover::setHeadlight(bool enable)
{
    if (enable)
    {
        setBuiltInFunctionState("Headlight", 1);
        coVRLighting::instance()->switchLight(coVRLighting::instance()->headlight, true);
    }
    else
    {
        setBuiltInFunctionState("Headlight", 0);
        coVRLighting::instance()->switchLight(coVRLighting::instance()->headlight, false);
    }
}

bool SystemCover::getPreloadSwitch()
{
    static bool firstTime = true;
    static bool preload = true;
    if (firstTime)
    {
        preload = !coCoviseConfig::isOn("COVER.Plugin.Vrml97.NoSwitchChildrenPreload", false);
        firstTime = false;
    }
    return preload;
}

float SystemCover::getSyncInterval()
{
    return coVRCollaboration::instance()->getSyncInterval();
}

void SystemCover::addViewpoint(VrmlScene *scene, VrmlNodeViewpoint *viewpoint)
{
    coCheckboxMenuItem *menuEntry;

    // add viewpoint to menu
    ViewpointEntry *vpe = new ViewpointEntry(viewpoint, scene);
    if (viewpoint == scene->bindableViewpointTop())
        menuEntry = new coCheckboxMenuItem(viewpoint->description(), true, cbg);
    else
        menuEntry = new coCheckboxMenuItem(viewpoint->description(), false, cbg);
    menuEntry->setMenuListener(vpe);
    viewpointMenu->add(menuEntry);
    vpe->setMenuItem(menuEntry);
    viewpointEntries.push_back(vpe);
}

bool SystemCover::removeViewpoint(VrmlScene *scene, const VrmlNodeViewpoint *viewpoint)
{
    (void)scene;
    maxEntryNumber = 0;
    for (list<ViewpointEntry *>::iterator it = viewpointEntries.begin();
         it != viewpointEntries.end(); it++)
    {
        if ((*it)->getViewpoint() == viewpoint)
        {
            delete *it;
            viewpointEntries.erase(it);

            for (it = viewpointEntries.begin();
                 it != viewpointEntries.end(); it++)
            {
                maxEntryNumber = (*it)->entryNumber;
            }
            return true;
        }
        else
        {
            maxEntryNumber = (*it)->entryNumber;
        }
    }

    return false;
}

bool SystemCover::setViewpoint(VrmlScene *scene, const VrmlNodeViewpoint *viewpoint)
{
    (void)scene;

    list<ViewpointEntry *>::iterator it = viewpointEntries.begin();
    while (it != viewpointEntries.end())
    {
        if ((*it)->getViewpoint() == viewpoint)
        {
            (*it)->getTUIItem()->setState(true);
        }
        else
        {
            (*it)->getTUIItem()->setState(false);
        }
        it++;
    }
    it = viewpointEntries.begin();
    while (it != viewpointEntries.end())
    {
        if ((*it)->getViewpoint() == viewpoint)
        {
            cbg->setState((*it)->getMenuItem(), true);
            return true;
        }
        else
        {
            it++;
        }
    }

    return false;
}

void SystemCover::setCurrentFile(const char *filename)
{
    Vrml97Plugin::plugin->isNewVRML = true;
    coVRCommunication::instance()->setCurrentFile(filename);
}

void SystemCover::setMenuVisibility(bool vis)
{
    viewpointMenu->setVisible(vis);
}

void SystemCover::setTimeStep(int ts) // set the timestep number for COVISE Animations
{
    coVRAnimationManager::instance()->setAnimationFrame(ts);
}

void SystemCover::setActivePerson(int p) // set the active Person
{
    Input::instance()->setActivePerson(p);
}

void SystemCover::setNavigationType(System::NavigationType nav)
{
    switch (nav)
    {
    case NAV_NONE:
        cover->enableNavigation("Walk");
        cover->disableNavigation("Walk");
        break;
    case NAV_FLY:
        cover->enableNavigation("Fly");
        break;
    case NAV_WALK:
        cover->enableNavigation("Walk");
        break;
    case NAV_EXAMINE:
        cover->enableNavigation("Xform");
        break;
    case NAV_DRIVE:
        cover->enableNavigation("Drive");
        break;
    case NAV_SCALE:
        cover->enableNavigation("Scale");
        break;
    default:
        fprintf(stderr, "SystemCover::setNavigationType: unknown navigation type\n");
        break;
    }
}

void SystemCover::setNavigationStepSize(double stepsize)
{
    coVRNavigationManager::instance()->setStepSize(stepsize);
}

void SystemCover::setNavigationDriveSpeed(double speed)
{
    cover->setNavigationValue("DriveSpeed", speed);
}

void SystemCover::setNearFar(float nearC, float farC)
{
    coVRConfig::instance()->setNearFar(nearC, farC);
}

double SystemCover::getAvatarHeight()
{
    return VRSceneGraph::instance()->floorHeight();
}

int SystemCover::getNumAvatars()
{
    return VRAvatarList::instance()->getNum();
}

bool SystemCover::getAvatarPositionAndOrientation(int num, float pos[3], float ori[4])
{
    if (num < 0 || num >= VRAvatarList::instance()->getNum())
        return false;

    osg::Matrix feet;
    feet = VRAvatarList::instance()->getAvatar(num)->schuheTransform->getMatrix();

    return getPositionAndOrientationFromMatrix(feet, pos, ori);
}

bool SystemCover::getViewerPositionAndOrientation(float pos[3], float ori[4])
{
    osg::Matrix invbase = cover->getInvBaseMat();
    osg::Matrix headmat = cover->getViewerMat();
    headmat *= invbase;

    return getPositionAndOrientationFromMatrix(headmat, pos, ori);
}

bool SystemCover::getLocalViewerPositionAndOrientation(float pos[3], float ori[4])
{
    osg::Matrix headmat = cover->getViewerMat();

    return getPositionAndOrientationFromMatrix(headmat, pos, ori);
}

bool SystemCover::getViewerFeetPositionAndOrientation(float pos[3], float ori[4])
{
    osg::Matrix invbase = cover->getInvBaseMat();
    osg::Matrix headmat = cover->getViewerMat();
    osg::Vec3 toFeet;
    toFeet = headmat.getTrans();
    toFeet[2] = getAvatarHeight();
    osg::Matrix feetmat;
    feetmat.makeTranslate(toFeet[0], toFeet[1], toFeet[2]);
    feetmat *= invbase;

    return getPositionAndOrientationFromMatrix(feetmat, pos, ori);
}

bool SystemCover::getPositionAndOrientationFromMatrix(const double *M, float pos[3], float ori[4])
{
    osg::Matrix mat;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            mat(i, j) = M[i * 4 + j];
    return getPositionAndOrientationFromMatrix(mat, pos, ori);
}

void SystemCover::getInvBaseMat(double *M)
{
    osg::Matrix mat = cover->getInvBaseMat();
    osg::Matrix rotMat;
    rotMat.makeRotate(-M_PI / 2.0, osg::Vec3(1.0, 0.0, 0.0));
    mat.preMult(rotMat);
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            M[i * 4 + j] = mat(i, j);
}

void SystemCover::getPositionAndOrientationOfOrigin(const double *M, float pos[3], float ori[4])
{
    osg::Matrix VRMLTrans;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            VRMLTrans(i, j) = M[i * 4 + j];

    osg::Matrix mat = cover->getInvBaseMat();
    osg::Matrix rotMat;
    rotMat.makeRotate(-M_PI / 2.0, osg::Vec3(1.0, 0.0, 0.0));
    osg::Matrix VRMLRotMat;
    VRMLRotMat.makeRotate(M_PI / 2.0, osg::Vec3(1.0, 0.0, 0.0));
    mat.postMult(rotMat);
    mat.postMult(VRMLTrans);
    mat.preMult(VRMLRotMat);

    //mat.getOrthoCoord(&coord);
    coCoord coord(mat);
    //mat.makeCoord(&coord);
    coord.makeMat(mat);
    if (pos)
    {
        for (int i = 0; i < 3; i++)
            pos[i] = mat(3, i);
    }
    if (ori)
    {
        osg::Quat q;
        //m.getOrthoQuat(q);
        q.set(mat);
        osg::Quat::value_type orient[4];
        q.getRotate(orient[3], orient[0], orient[1], orient[2]);
        for (int i = 0; i < 4; i++)
        {
            ori[i] = orient[i];
        }
    }
}

bool SystemCover::getPositionAndOrientationFromMatrix(const osg::Matrix &mat, float pos[3], float ori[4])
{
    if (!ViewerOsg::viewer)
        return false;

    osg::Matrix VRMLRootMat = ViewerOsg::viewer->VRMLRoot->getMatrix();
    osg::Matrix invVRMLRootMat;
    invVRMLRootMat.invert(VRMLRootMat);
    osg::Matrix m = VRMLRootMat * mat * invVRMLRootMat;
    coCoord coord(m);
    coord.makeMat(m);
    if (pos)
    {
        for (int i = 0; i < 3; i++)
            pos[i] = m(3, i);
    }
    if (ori)
    {
        osg::Quat q;
        q.set(m);
        osg::Quat::value_type orient[4];
        q.getRotate(orient[3], orient[0], orient[1], orient[2]);
        for (int i = 0; i < 4; i++)
        {
            ori[i] = orient[i];
        }
    }

    return true;
}

void SystemCover::transformByMatrix(const double *M, float pos[3], float ori[4])
{
    osg::Matrix mat;
    osg::Matrix imat;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            imat(i, j) = M[i * 4 + j];

    mat.invert(imat);
    osg::Matrix mat2;
    osg::Matrix rotMat;
    mat2.makeTranslate(pos[0], pos[1], pos[2]);
    rotMat.makeRotate(ori[3], osg::Vec3(ori[0], ori[1], ori[2]));
    osg::Matrix m = rotMat * mat2 * mat;
    coCoord coord(m);
    //m.makeCoord(&coord);
    coord.makeMat(m);
    if (pos)
    {
        for (int i = 0; i < 3; i++)
            pos[i] = m(3, i);
    }
    if (ori)
    {
        osg::Quat q;
        //m.getOrthoQuat(q);
        q.set(m);
        osg::Quat::value_type orient[4];
        q.getRotate(orient[3], orient[0], orient[1], orient[2]);
        for (int i = 0; i < 4; i++)
        {
            ori[i] = orient[i];
        }
    }
}

bool SystemCover::loadPlugin(const char *name)
{
    return cover->addPlugin(name);
}

std::string SystemCover::getConfigEntry(const char *key)
{
    return coCoviseConfig::getEntry(key);
}

bool SystemCover::getConfigState(const char *key, bool defaultVal)
{
    return coCoviseConfig::isOn(key, defaultVal);
}

void SystemCover::storeInline(const char *name, const Viewer::Object d_viewerObject)
{
    if (d_viewerObject)
    {
        osg::Node *osgNode = ((osgViewerObject *)d_viewerObject)->pNode.get();
        if (osgNode)
        {

            // run optimization over the scene graph
            osgUtil::Optimizer optimzer;
            optimzer.optimize(osgNode);
            std::string n(name);
            n += ".osgb";
            osgDB::writeNodeFile(*osgNode, n.c_str());
        }
    }
}

Viewer::Object SystemCover::getInline(const char *name)
{
    osg::Group *g = new osg::Group;
    std::string n(name);
    std::string cached = n + ".osgb";

    coVRFileManager::instance()->loadFile(cached.c_str(), NULL, g);
    if (g->getNumChildren() > 0)
    {
        osg::Node *loadedNode = g->getChild(0);
        loadedNode->ref();
        g->removeChild(loadedNode);
        loadedNode->unref_nodelete(); //refcount now back to 0 but the node is not deleted
        //will be added to something later on and thus deleted when removed from there.
        return ((Viewer::Object)loadedNode);
    }

    coVRFileManager::instance()->loadFile(n.c_str(), NULL, g);
    {
        if (g->getNumChildren() > 0)
        {
            osg::Node *loadedNode = g->getChild(0);
            loadedNode->ref();
            g->removeChild(loadedNode);
            loadedNode->unref_nodelete(); //refcount now back to 0 but the node is not deleted
            //will be added to something later on and thus deleted when removed from there.
            return ((Viewer::Object)loadedNode);
        }
    }

    return 0L;
}

void SystemCover::insertObject(Viewer::Object d_viewerObject, Viewer::Object sgObject)
{
    ((osgViewerObject *)d_viewerObject)->pNode = (osg::Node *)sgObject;
    ViewerOsg::viewer->addToScene(((osgViewerObject *)d_viewerObject));
}

float SystemCover::getLODScale()
{
    return coVRConfig::instance()->getLODScale();
}

float SystemCover::defaultCreaseAngle()
{
    static float angle = 0.0;
    static bool firstTime = true;
    if (firstTime)
    {
        angle = coCoviseConfig::getFloat("COVER.Plugin.Vrml97.DefaultCreaseAngle", 0.0);
        firstTime = false;
    }
    return angle;
}