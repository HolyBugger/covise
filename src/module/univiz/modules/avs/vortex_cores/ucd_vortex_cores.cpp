/* This file is part of COVISE.

   You can use it under the terms of the GNU Lesser General Public License
   version 2.1 or later, see lgpl-2.1.txt.

 * License: LGPL 2+ */

/* mod_gen Version 1                                                      */
/* Module Name: "ucd vortex cores" (Mapper) (Subroutine)                  */
/* Author: Ronald Peikert (and Filip Sadlo 2006)                          */
/* Date Created: Thu Jun 28 14:18:12 2001                                 */
/*                                                                        */
/* This file is automatically generated by the Module Generator (mod_gen) */
/* Please do not modify or move the contents of this comment block as     */
/* mod_gen needs it in order to read module sources back in.              */
/*                                                                        */
/* input 0 "ucd" ucd REQUIRED                                             */
/* output 0 "geom" geom Polyhedron                                        */
/* param 0 "method" radio_buttons "Levy" "Levy:Sujudi-Haimes" ":"         */
/* param 1 "variant" radio_buttons "triangle" "triangle:quad newton" ":"  */
/* param 2 "min vertices" typein_integer 10 INT_UNBOUND INT_UNBOUND       */
/* param 3 "max exceptions" typein_integer 3 INT_UNBOUND INT_UNBOUND      */
/* param 4 "min strength" typein_real 1.00000 FLOAT_UNBOUND FLOAT_UNBOUND */
/* param 5 "max angle" typein_real 30.0000 FLOAT_UNBOUND FLOAT_UNBOUND    */
/* End of Module Description Comments                                     */

#include <stdio.h>
#include <avs/avs.h>
#include <avs/port.h>
#include <avs/field.h>
#include <avs/geom.h>
#include <avs/ucd_defs.h>

/* ----> START OF USER-SUPPLIED CODE SECTION #1 (INCLUDE FILES, GLOBAL VARIABLES)*/

#include <string.h>

#include "avs_ext.h"
#include "unstructured.h"
#include "unisys.h"
#include "unigeom.h"
#include "computeVortexCores.h"

#include "ucd_vortex_cores_impl.cpp" // ### including .cpp

static Unstructured *unst = NULL;

void hack_ucd(UCD_structure *ucd);

/* <---- END OF USER-SUPPLIED CODE SECTION #1                            */

/* *****************************************/
/*  Module Description                     */
/* *****************************************/
int ucd_vortex_cores_desc()
{

    int in_port, out_port, param;
    extern int ucd_vortex_cores_compute(UCD_structure * ucd, GEOMedit_list * geom,
                                        char *velocity, char *method, char *variant, int min_vertices,
                                        int max_exceptions, float *min_strength, float *max_angle);

    AVSset_module_name("ucd vortex cores", MODULE_MAPPER);

    /* Input Port Specifications               */
    in_port = AVScreate_input_port("ucd", "ucd", REQUIRED);

    /* Output Port Specifications              */
    out_port = AVScreate_output_port("geom", "geom");

    /* Parameter Specifications                */
    param = AVSadd_parameter("velocity", "choice", "", "", ":");
    AVSconnect_widget(param, "choice_browser");

    param = AVSadd_parameter("method", "choice", "Levy",
                             "Levy:Sujudi-Haimes", ":");
    AVSconnect_widget(param, "radio_buttons");

    param = AVSadd_parameter("variant", "choice", "triangle",
                             "triangle:quad newton", ":*/");
    AVSconnect_widget(param, "radio_buttons");

    param = AVSadd_parameter("min vertices", "integer", 10, 2, INT_UNBOUND);
    AVSconnect_widget(param, "typein_integer");

    param = AVSadd_parameter("max exceptions", "integer", 3, 1, INT_UNBOUND);
    AVSconnect_widget(param, "typein_integer");

    param = AVSadd_float_parameter("min strength", 1.00000, 0.0, FLOAT_UNBOUND);
    AVSconnect_widget(param, "typein_real");

    param = AVSadd_float_parameter("max angle", 30.0, 0.0, 90.0);
    AVSconnect_widget(param, "typein_real");

    AVSset_compute_proc((int (*)())ucd_vortex_cores_compute);
    /* ----> START OF USER-SUPPLIED CODE SECTION #2 (ADDITIONAL SPECIFICATION INFO)*/
    /* <---- END OF USER-SUPPLIED CODE SECTION #2                            */
    return (1);
}

/* *****************************************/
/* Module Compute Routine                  */
/* *****************************************/
int ucd_vortex_cores_compute(UCD_structure *ucd, GEOMedit_list *geom,
                             char *velocity, char *method, char *variant, int min_vertices,
                             int max_exceptions, float *min_strength, float *max_angle)
{

    /* ----> START OF USER-SUPPLIED CODE SECTION #3 (COMPUTE ROUTINE BODY)   */

    /* if (AVSinput_changed("ucd", 0)) hack_ucd(ucd); */

    /* Check ucd */
    if (ucd_findNodeCompByVeclen(ucd, 3, 0) < 0)
    {
        AVSerror("UCD must have veclen=3");
        return 0;
    }

    int variantNr;
    variantNr = AVSchoice_number("variant", variant);

    int methodNr;
    methodNr = AVSchoice_number("method", method);

    // setup unstructured wrapper for input
    if (AVSinput_changed("ucd", 0))
    {
        if (unst)
            delete unst;
        unst = new Unstructured(ucd);
    }

    int compV = ucd_processCompChoice(ucd, "ucd", velocity, "velocity", 3,
                                      unst->getVectorNodeDataComponent());
    if (compV >= 0)
        unst->selectVectorNodeData(compV);

    // system wrapper
    UniSys us;

    // geometry wrapper for output
    UniGeom ugeom = UniGeom(geom);

    // compute
    ucd_vortex_cores_impl(&us, unst, compV, methodNr, variantNr,
                          min_vertices, max_exceptions,
                          *min_strength, *max_angle, &ugeom);

    /* <---- END OF USER-SUPPLIED CODE SECTION #3                            */
    return (1);
}

/* ***********************************************************************/
/* Initialization for modules contained in this file.                    */
/* ***********************************************************************/
static int((*mod_list[])()) = {
    ucd_vortex_cores_desc
};
#define NMODS (sizeof(mod_list) / sizeof(char *))

extern "C" {
void AVSinit_modules()
{
    AVSinit_from_module_list(mod_list, NMODS);
}
}

/* ----> START OF USER-SUPPLIED CODE SECTION #4 (SUBROUTINES, FUNCTIONS, UTILITY ROUTINES)*/

/* <---- END OF USER-SUPPLIED CODE SECTION #4                            */