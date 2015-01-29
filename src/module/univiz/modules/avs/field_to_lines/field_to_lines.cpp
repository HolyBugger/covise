/* This file is part of COVISE.

   You can use it under the terms of the GNU Lesser General Public License
   version 2.1 or later, see lgpl-2.1.txt.

 * License: LGPL 2+ */

/* mod_gen Version 1                                                      */
/* Module Name: "field to lines" (Mapper) (Subroutine)                  */
/* Author: Filip Sadlo                          */
/* Date Created: Thu Jun 1 17:18:12 2007                                 */
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
// ### TODO adapt defs above

#include <stdio.h>
#include <avs/avs.h>
#include <avs/port.h>
#include <avs/field.h>
#include <avs/geom.h>
#include <avs/ucd_defs.h>

/* ----> START OF USER-SUPPLIED CODE SECTION #1 (INCLUDE FILES, GLOBAL VARIABLES)*/

#include <string.h>

#include "avs_ext.h"
#include "unifield.h"
#include "unisys.h"
#include "unigeom.h"

#include "field_to_lines_impl.cpp" // ### including .cpp

/* <---- END OF USER-SUPPLIED CODE SECTION #1                            */

/* *****************************************/
/*  Module Description                     */
/* *****************************************/
int field_to_lines_desc()
{

    int in_port, out_port, param;
    extern int field_to_lines_compute(AVSfield_float * line_field,
                                      GEOMedit_list * geom,
                                      int nodes_x, int nodes_y, int nodes_z,
                                      int stride);

    AVSset_module_name("field to lines", MODULE_MAPPER);

    /* Input Port Specifications               */
    in_port = AVScreate_input_port("line field", "field 2D 3-space irregular float", REQUIRED);

    /* Output Port Specifications              */
    out_port = AVScreate_output_port("geom", "geom");

    /* Parameter Specifications                */
    param = AVSadd_parameter("nodes x", "integer", 10, 1, INT_MAX);
    AVSconnect_widget(param, "typein_integer");

    param = AVSadd_parameter("nodes y", "integer", 10, 1, INT_MAX);
    AVSconnect_widget(param, "typein_integer");

    param = AVSadd_parameter("nodes z", "integer", 10, 1, INT_MAX);
    AVSconnect_widget(param, "typein_integer");

    param = AVSadd_parameter("stride", "integer", 1, 1, INT_MAX);
    AVSconnect_widget(param, "typein_integer");

    AVSset_compute_proc((int (*)())field_to_lines_compute);
    /* ----> START OF USER-SUPPLIED CODE SECTION #2 (ADDITIONAL SPECIFICATION INFO)*/
    /* <---- END OF USER-SUPPLIED CODE SECTION #2                            */
    return (1);
}

/* *****************************************/
/* Module Compute Routine                  */
/* *****************************************/
int field_to_lines_compute(AVSfield_float *line_field,
                           GEOMedit_list *geom,
                           int nodes_x, int nodes_y, int nodes_z,
                           int stride)
{

    /* ----> START OF USER-SUPPLIED CODE SECTION #3 (COMPUTE ROUTINE BODY)   */

    // system wrapper
    UniSys us;

    // wrapper for input field
    UniField *unif = new UniField((AVSfield *)line_field);

    // geometry wrapper for output
    UniGeom ugeom = UniGeom(geom);

    // compute
    if (!field_to_lines_impl(&us, unif, nodes_x, nodes_y, nodes_z, stride, &ugeom, NULL, NULL))
    {
        delete unif;
        return 0;
    }

    // delete field wrapper (but not the field)
    delete unif;

    /* <---- END OF USER-SUPPLIED CODE SECTION #3                            */
    return (1);
}

/* ***********************************************************************/
/* Initialization for modules contained in this file.                    */
/* ***********************************************************************/
static int((*mod_list[])()) = {
    field_to_lines_desc
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