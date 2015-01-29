/* This file is part of COVISE.

   You can use it under the terms of the GNU Lesser General Public License
   version 2.1 or later, see lgpl-2.1.txt.

 * License: LGPL 2+ */

#ifndef CUTTING_TABLE_H
#define CUTTING_TABLE_H

namespace covise
{

static cutting_info Hex_Table[256] = {
    { /* 0: no */
      {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 1: yes */
      {
        0, 1, 0, 3, 4, 0, 0, 0, 0, 0, 0, 0
      },
      3
    },
    { /* 2: yes */
      {
        0, 1, 1, 5, 2, 1, 0, 0, 0, 0, 0, 0
      },
      3
    },
    { /* 3: yes */
      {
        0, 4, 1, 5, 2, 1, 3, 0, 0, 0, 0, 0
      },
      4
    },
    { /* 4: yes */
      {
        3, 2, 2, 1, 2, 6, 0, 0, 0, 0, 0, 0
      },
      3
    },
    { /* 5: err 1! */
      {
        0, 1, 0, 4, 3, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 6: yes */
      {
        0, 1, 1, 5, 2, 6, 3, 2, 0, 0, 0, 0
      },
      4
    },
    { /* 7: yes */
      {
        3, 2, 3, 0, 0, 4, 1, 5, 2, 6, 0, 0
      },
      5
    },
    { /* 8: yes */
      {
        3, 2, 3, 7, 3, 0, 0, 0, 0, 0, 0, 0
      },
      3
    },
    { /* 9: yes */
      {
        0, 1, 3, 2, 3, 7, 0, 4, 0, 0, 0, 0
      },
      4
    },
    { /* 10: err 1! */
      {
        0, 1, 1, 5, 2, 1, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 11: yes */
      {
        3, 2, 3, 7, 0, 4, 1, 5, 2, 1, 0, 0
      },
      5
    },
    { /* 12: yes */
      {
        3, 7, 3, 0, 2, 1, 2, 6, 0, 0, 0, 0
      },
      4
    },
    { /* 13: yes */
      {
        0, 1, 2, 1, 2, 6, 3, 7, 0, 4, 0, 0
      },
      5
    },
    { /* 14: yes */
      {
        0, 1, 1, 5, 2, 6, 3, 7, 3, 0, 0, 0
      },
      5
    },
    { /* 15: yes */
      {
        0, 4, 1, 5, 2, 6, 3, 7, 0, 0, 0, 0
      },
      4
    },
    { /* 16: yes */
      {
        4, 5, 4, 0, 4, 7, 0, 0, 0, 0, 0, 0
      },
      3
    },
    { /* 17: yes */
      {
        0, 1, 0, 3, 4, 7, 4, 5, 0, 0, 0, 0
      },
      4
    },
    { /* 18: err 1! */
      {
        0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 19: yes */
      {
        4, 5, 1, 5, 2, 1, 3, 0, 7, 4, 0, 0
      },
      5
    },
    { /* 20: yes */
      {
        4, 5, 0, 4, 7, 4, 0, 0, 0, 0, 0, 0
      },
      3
    },
    { /* 21: err 1! */
      {
        0, 1, 4, 5, 7, 4, 3, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 22: err 1! */
      {
        0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 23: yes */
      {
        4, 5, 1, 5, 2, 6, 3, 2, 3, 0, 7, 4
      },
      6
    },
    { /* 24: err 1! */
      {
        4, 5, 7, 4, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 25: yes */
      {
        0, 1, 3, 2, 3, 7, 7, 4, 4, 5, 0, 0
      },
      5
    },
    { /* 26: err 1! */
      {
        0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 27: yes */
      {
        4, 5, 1, 5, 2, 1, 2, 3, 3, 7, 7, 4
      },
      6
    },
    { /* 28: err 1! */
      {
        4, 5, 7, 4, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 29: yes */
      {
        0, 1, 2, 1, 2, 6, 3, 7, 7, 4, 4, 5
      },
      6
    },
    { /* 30: err 1! */
      {
        0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 31: yes */
      {
        4, 5, 1, 5, 2, 6, 3, 7, 7, 4, 0, 0
      },
      5
    },
    { /* 32: yes */
      {
        4, 5, 6, 5, 1, 5, 0, 0, 0, 0, 0, 0
      },
      3
    },
    { /* 33: err 1! */
      {
        0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 34: yes */
      {
        0, 1, 4, 5, 6, 5, 2, 1, 0, 0, 0, 0
      },
      4
    },
    { /* 35: yes */
      {
        4, 5, 6, 5, 2, 1, 3, 0, 0, 4, 0, 0
      },
      5
    },
    { /* 36: err 1! */
      {
        4, 5, 6, 5, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 37: err 1! */
      {
        0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 38: yes */
      {
        0, 1, 4, 5, 6, 5, 2, 6, 3, 2, 0, 0
      },
      5
    },
    { /* 39: yes */
      {
        4, 5, 6, 5, 2, 6, 3, 2, 3, 0, 0, 4
      },
      6
    },
    { /* 40: yes */
      {
        4, 5, 6, 5, 1, 5, 0, 0, 0, 0, 0, 0
      },
      3
    },
    { /* 41: err 1! */
      {
        0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 42: err 1! */
      {
        0, 1, 4, 5, 6, 5, 2, 1, 0, 0, 0, 0
      },
      0
    },
    { /* 43: yes */
      {
        4, 5, 6, 5, 2, 1, 3, 2, 3, 7, 0, 4
      },
      6
    },
    { /* 44: err 1! */
      {
        4, 5, 6, 5, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 45: err 1! */
      {
        0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 46: yes */
      {
        0, 1, 4, 5, 6, 5, 2, 6, 3, 7, 3, 0
      },
      6
    },
    { /* 47: yes */
      {
        4, 5, 6, 5, 2, 6, 3, 7, 0, 4, 0, 0
      },
      5
    },
    { /* 48: yes */
      {
        0, 4, 7, 4, 6, 5, 1, 5, 0, 0, 0, 0
      },
      4
    },
    { /* 49: yes */
      {
        0, 1, 3, 0, 7, 4, 6, 5, 1, 5, 0, 0
      },
      5
    },
    { /* 50: yes */
      {
        0, 1, 0, 4, 7, 4, 6, 5, 2, 1, 0, 0
      },
      5
    },
    { /* 51: yes */
      {
        2, 1, 3, 0, 7, 4, 6, 5, 0, 0, 0, 0
      },
      4
    },
    { /* 52: err 1! */
      {
        3, 2, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 53: err 1! */
      {
        0, 1, 1, 5, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 54: yes */
      {
        0, 1, 0, 4, 7, 4, 6, 5, 2, 6, 3, 2
      },
      6
    },
    { /* 55: yes */
      {
        3, 2, 3, 0, 7, 4, 6, 5, 2, 6, 0, 0
      },
      5
    },
    { /* 56: err 1! */
      {
        3, 2, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 57: yes */
      {
        0, 1, 3, 2, 3, 7, 7, 4, 6, 5, 1, 5
      },
      6
    },
    { /* 58: err 1! */
      {
        0, 1, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 59: yes */
      {
        3, 2, 3, 7, 7, 4, 6, 5, 2, 1, 0, 0
      },
      5
    },
    { /* 60: err 1! */
      {
        0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 61: err 1! */
      {
        0, 1, 1, 5, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 62: err 1! */
      {
        0, 1, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 63: yes */
      {
        3, 7, 7, 4, 6, 5, 2, 6, 0, 0, 0, 0
      },
      4
    },
    { /* 64: yes */
      {
        7, 6, 2, 6, 6, 5, 0, 0, 0, 0, 0, 0
      },
      3
    },
    { /* 65: yes */
      {
        0, 1, 0, 3, 0, 4, 0, 0, 0, 0, 0, 0
      },
      3
    },
    { /* 66: err 1! */
      {
        0, 1, 1, 5, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 67: err 1! */
      {
        7, 6, 2, 6, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 68: yes */
      {
        3, 2, 2, 1, 6, 5, 7, 6, 0, 0, 0, 0
      },
      4
    },
    { /* 69: err 1! */
      {
        0, 1, 0, 4, 3, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 70: yes */
      {
        0, 1, 1, 5, 6, 5, 7, 6, 3, 2, 0, 0
      },
      5
    },
    { /* 71: yes */
      {
        3, 2, 3, 0, 0, 4, 1, 5, 6, 5, 7, 6
      },
      6
    },
    { /* 72: err 1! */
      {
        3, 2, 3, 0, 3, 7, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 73: err 1! */
      {
        0, 1, 0, 4, 3, 7, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 74: err 1! */
      {
        0, 1, 1, 5, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 75: err 1! */
      {
        3, 2, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 76: yes */
      {
        7, 6, 3, 7, 3, 0, 2, 1, 6, 5, 0, 0
      },
      5
    },
    { /* 77: yes */
      {
        0, 1, 2, 1, 6, 5, 7, 6, 3, 7, 0, 4
      },
      6
    },
    { /* 78: yes */
      {
        0, 1, 1, 5, 6, 5, 7, 6, 3, 7, 3, 0
      },
      6
    },
    { /* 79: yes */
      {
        7, 6, 3, 7, 0, 4, 1, 5, 6, 5, 0, 0
      },
      5
    },
    { /* 80: err 1! */
      {
        4, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 81: err 1! */
      {
        0, 1, 4, 5, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 82: err 1! */
      {
        0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 83: err 1! */
      {
        4, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 84: err 1! */
      {
        4, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 85: err 1! */
      {
        0, 1, 4, 5, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 86: err 1! */
      {
        0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 87: err 1! */
      {
        4, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 88: err 1! */
      {
        4, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 89: err 1! */
      {
        0, 1, 4, 5, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 90: err 1! */
      {
        0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 91: err 1! */
      {
        4, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 92: err 1! */
      {
        4, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 93: err 1! */
      {
        0, 1, 4, 5, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 94: err 1! */
      {
        0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 95: err 1! */
      {
        4, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 96: yes */
      {
        4, 5, 7, 6, 2, 6, 1, 5, 0, 0, 0, 0
      },
      4
    },
    { /* 97: err 1! */
      {
        0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 98: yes */
      {
        0, 1, 4, 5, 7, 6, 2, 6, 2, 1, 0, 0
      },
      5
    },
    { /* 99: yes */
      {
        4, 5, 7, 6, 2, 6, 2, 1, 3, 0, 0, 4
      },
      6
    },
    { /* 100: yes */
      {
        4, 5, 7, 6, 3, 2, 2, 1, 1, 5, 0, 0
      },
      5
    },
    { /* 101: err 1! */
      {
        0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 102: yes */
      {
        0, 1, 4, 5, 7, 6, 3, 2, 0, 0, 0, 0
      },
      4
    },
    { /* 103: yes */
      {
        4, 5, 7, 6, 3, 2, 3, 0, 0, 4, 0, 0
      },
      5
    },
    { /* 104: err 1! */
      {
        4, 5, 7, 6, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 105: err 1! */
      {
        0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 106: err 1! */
      {
        0, 1, 4, 5, 7, 6, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 107: err 1! */
      {
        4, 5, 7, 6, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 108: yes */
      {
        4, 5, 7, 6, 3, 7, 3, 0, 2, 1, 1, 5
      },
      6
    },
    { /* 109: err 1! */
      {
        0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 110: yes */
      {
        0, 1, 4, 5, 7, 6, 3, 7, 3, 0, 0, 0
      },
      5
    },
    { /* 111: yes */
      {
        4, 5, 7, 6, 3, 7, 0, 4, 0, 0, 0, 0
      },
      4
    },
    { /* 112: yes */
      {
        7, 6, 2, 6, 1, 5, 0, 4, 7, 4, 0, 0
      },
      5
    },
    { /* 113: yes */
      {
        0, 1, 3, 0, 7, 4, 7, 6, 2, 6, 1, 5
      },
      6
    },
    { /* 114: yes */
      {
        0, 1, 0, 4, 7, 4, 7, 6, 2, 6, 2, 1
      },
      6
    },
    { /* 115: yes */
      {
        7, 6, 2, 6, 2, 1, 3, 0, 7, 4, 0, 0
      },
      5
    },
    { /* 116: yes */
      {
        3, 2, 2, 1, 1, 5, 0, 4, 7, 4, 7, 6
      },
      6
    },
    { /* 117: err 1! */
      {
        0, 1, 1, 5, 2, 1, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 118: yes */
      {
        0, 1, 0, 4, 7, 4, 7, 6, 3, 2, 0, 0
      },
      5
    },
    { /* 119: yes */
      {
        3, 2, 3, 0, 7, 4, 7, 6, 0, 0, 0, 0
      },
      4
    },
    { /* 120: err 1! */
      {
        3, 2, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 121: err 1! */
      {
        0, 1, 1, 5, 2, 6, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 122: err 1! */
      {
        0, 1, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 123: err 1! */
      {
        3, 2, 2, 1, 2, 6, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 124: err 1! */
      {
        7, 6, 3, 7, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 125: yes */
      {
        0, 1, 2, 1, 1, 5, 0, 0, 0, 0, 0, 0
      },
      3
    },
    { /* 126: err 1! */
      {
        0, 1, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 127: yes */
      {
        7, 6, 3, 7, 7, 4, 0, 0, 0, 0, 0, 0
      },
      3
    },
    { /* 128: yes */
      {
        7, 6, 7, 4, 3, 7, 0, 0, 0, 0, 0, 0
      },
      3
    },
    { /* 129: err 1! */
      {
        0, 1, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 130: yes */
      {
        0, 1, 1, 5, 2, 1, 0, 0, 0, 0, 0, 0
      },
      3
    },
    { /* 131: err 1! */
      {
        7, 6, 3, 7, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 132: err 1! */
      {
        3, 2, 2, 1, 2, 6, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 133: err 1! */
      {
        0, 1, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 134: err 1! */
      {
        0, 1, 1, 5, 2, 6, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 135: err 1! */
      {
        3, 2, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 136: yes */
      {
        3, 2, 7, 6, 7, 4, 3, 0, 0, 0, 0, 0
      },
      4
    },
    { /* 137: yes */
      {
        0, 1, 3, 2, 7, 6, 7, 4, 0, 4, 0, 0
      },
      5
    },
    { /* 138: err 1! */
      {
        0, 1, 1, 5, 2, 1, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 139: yes */
      {
        3, 2, 7, 6, 7, 4, 0, 4, 1, 5, 2, 1
      },
      6
    },
    { /* 140: yes */
      {
        7, 6, 7, 4, 3, 0, 2, 1, 2, 6, 0, 0
      },
      5
    },
    { /* 141: yes */
      {
        0, 1, 2, 1, 2, 6, 7, 6, 7, 4, 0, 4
      },
      6
    },
    { /* 142: yes */
      {
        0, 1, 1, 5, 2, 6, 7, 6, 7, 4, 3, 0
      },
      6
    },
    { /* 143: yes */
      {
        7, 6, 7, 4, 0, 4, 1, 5, 2, 6, 0, 0
      },
      5
    },
    { /* 144: yes */
      {
        4, 5, 0, 4, 3, 7, 7, 6, 0, 0, 0, 0
      },
      4
    },
    { /* 145: yes */
      {
        0, 1, 3, 0, 3, 7, 7, 6, 4, 5, 0, 0
      },
      5
    },
    { /* 146: err 1! */
      {
        0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 147: yes */
      {
        4, 5, 1, 5, 2, 1, 3, 0, 3, 7, 7, 6
      },
      6
    },
    { /* 148: err 1! */
      {
        4, 5, 7, 6, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 149: err 1! */
      {
        0, 1, 4, 5, 7, 6, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 150: err 1! */
      {
        0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 151: err 1! */
      {
        4, 5, 7, 6, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 152: yes */
      {
        4, 5, 0, 4, 3, 0, 3, 2, 7, 6, 0, 0
      },
      5
    },
    { { 0, 1, 3, 2, 7, 6, 4, 5, 0, 0, 0, 0 }, 4 },
    /* 153: yes */ //done
    { /* 154: err 1! */
      {
        0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 155: yes */
      {
        4, 5, 1, 5, 2, 1, 3, 2, 7, 6, 0, 0
      },
      5
    },
    { /* 156: yes */
      {
        4, 5, 0, 4, 3, 0, 2, 1, 2, 6, 7, 6
      },
      6
    },
    { /* 157: yes */
      {
        0, 1, 2, 1, 2, 6, 7, 6, 4, 5, 0, 0
      },
      5
    },
    { /* 158: err 1! */
      {
        0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 159: yes */
      {
        4, 5, 1, 5, 2, 6, 7, 6, 0, 0, 0, 0
      },
      4
    },
    { /* 160: err 1! */
      {
        4, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 161: err 1! */
      {
        0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 162: err 1! */
      {
        0, 1, 4, 5, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 163: err 1! */
      {
        4, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 164: err 1! */
      {
        4, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 165: err 1! */
      {
        0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 166: err 1! */
      {
        0, 1, 4, 5, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 167: err 1! */
      {
        4, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 168: err 1! */
      {
        4, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 169: err 1! */
      {
        0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 170: err 1! */
      {
        0, 1, 4, 5, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 171: err 1! */
      {
        4, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 172: err 1! */
      {
        4, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 173: err 1! */
      {
        0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 174: err 1! */
      {
        0, 1, 4, 5, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 175: err 1! */
      {
        4, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 176: yes */
      {
        7, 6, 6, 5, 1, 5, 0, 4, 3, 7, 0, 0
      },
      5
    },
    { /* 177: yes */
      {
        0, 1, 3, 0, 3, 7, 7, 6, 6, 5, 1, 5
      },
      6
    },
    { /* 178: yes */
      {
        0, 1, 0, 4, 3, 7, 7, 6, 6, 5, 2, 1
      },
      6
    },
    { /* 179: yes */
      {
        7, 6, 6, 5, 2, 1, 3, 0, 3, 7, 0, 0
      },
      5
    },
    { /* 180: err 1! */
      {
        3, 2, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 181: err 1! */
      {
        0, 1, 1, 5, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 182: err 1! */
      {
        0, 1, 0, 4, 3, 7, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 183: err 1! */
      {
        3, 2, 3, 0, 3, 7, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 184: yes */
      {
        3, 2, 7, 6, 6, 5, 1, 5, 0, 4, 3, 0
      },
      6
    },
    { /* 185: yes */
      {
        0, 1, 3, 2, 7, 6, 6, 5, 1, 5, 0, 0
      },
      5
    },
    { /* 186: err 1! */
      {
        0, 1, 0, 4, 3, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 187: yes */
      {
        3, 2, 7, 6, 6, 5, 2, 1, 0, 0, 0, 0
      },
      4
    },
    { /* 188: err 1! */
      {
        7, 6, 2, 6, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 189: err 1! */
      {
        0, 1, 1, 5, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 190: yes */
      {
        0, 1, 0, 4, 3, 0, 0, 0, 0, 0, 0, 0
      },
      3
    },
    { /* 191: yes */
      {
        7, 6, 5, 6, 6, 2, 0, 0, 0, 0, 0, 0
      },
      3
    },
    { /* 192: yes */
      {
        3, 7, 2, 6, 6, 5, 7, 4, 0, 0, 0, 0
      },
      4
    },
    { /* 193: err 1! */
      {
        0, 1, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 194: err 1! */
      {
        0, 1, 1, 5, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 195: err 1! */
      {
        0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 196: yes */
      {
        3, 2, 2, 1, 6, 5, 7, 4, 3, 7, 0, 0
      },
      5
    },
    { /* 197: err 1! */
      {
        0, 1, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 198: yes */
      {
        0, 1, 1, 5, 6, 5, 7, 4, 3, 7, 3, 2
      },
      6
    },
    { /* 199: err 1! */
      {
        3, 2, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 200: yes */
      {
        3, 2, 2, 6, 6, 5, 7, 4, 3, 0, 0, 0
      },
      5
    },
    { { 0, 1, 3, 2, 2, 6, 6, 5, 4, 7, 0, 4 }, 6 },
    /* 201: yes */ //done
    { /* 202: err 1! */
      {
        0, 1, 1, 5, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 203: err 1! */
      {
        3, 2, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 204: yes */
      {
        2, 1, 6, 5, 7, 4, 3, 0, 0, 0, 0, 0
      },
      4
    },
    { /* 205: yes */
      {
        0, 1, 2, 1, 6, 5, 7, 4, 0, 4, 0, 0
      },
      5
    },
    { /* 206: yes */
      {
        0, 1, 1, 5, 6, 5, 7, 4, 3, 0, 0, 0
      },
      5
    },
    { /* 207: yes */
      {
        0, 4, 1, 5, 6, 5, 7, 4, 0, 0, 0, 0
      },
      4
    },
    { /* 208: yes */
      {
        4, 5, 0, 4, 3, 7, 2, 6, 6, 5, 0, 0
      },
      5
    },
    { /* 209: yes */
      {
        0, 1, 3, 0, 3, 7, 2, 6, 6, 5, 4, 5
      },
      6
    },
    { /* 210: err 1! */
      {
        0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 211: err 1! */
      {
        4, 5, 6, 5, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 212: yes */
      {
        4, 5, 0, 4, 3, 7, 3, 2, 2, 1, 6, 5
      },
      6
    },
    { /* 213: err 1! */
      {
        0, 1, 4, 5, 6, 5, 2, 1, 0, 0, 0, 0
      },
      0
    },
    { /* 214: err 1! */
      {
        0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 215: yes */
      {
        4, 5, 1, 5, 6, 5, 0, 0, 0, 0, 0, 0
      },
      3
    },
    { /* 216: yes */
      {
        4, 5, 0, 4, 0, 3, 3, 2, 2, 6, 6, 5
      },
      6
    },
    { /* 217: yes */
      {
        0, 1, 3, 2, 2, 6, 6, 5, 4, 5, 0, 0
      },
      5
    },
    { /* 218: err 1! */
      {
        0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 219: err 1! */
      {
        4, 5, 6, 5, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 220: yes */
      {
        4, 5, 0, 4, 0, 3, 2, 1, 6, 5, 0, 0
      },
      5
    },
    { /* 221: yes */
      {
        0, 1, 1, 2, 6, 5, 5, 4, 0, 0, 0, 0
      },
      4
    },
    { /* 222: err 1! */
      {
        0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 223: yes */
      {
        4, 5, 1, 5, 6, 5, 0, 0, 0, 0, 0, 0
      },
      3
    },
    { /* 224: yes */
      {
        4, 5, 7, 4, 3, 7, 2, 6, 1, 5, 0, 0
      },
      5
    },
    { /* 225: err 1! */
      {
        0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 226: yes */
      {
        0, 1, 4, 5, 7, 4, 3, 7, 2, 6, 2, 1
      },
      6
    },
    { /* 227: err 1! */
      {
        4, 5, 7, 4, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 228: yes */
      {
        4, 5, 7, 4, 3, 7, 3, 2, 2, 1, 1, 5
      },
      6
    },
    { /* 229: err 1! */
      {
        0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 230: yes */
      {
        0, 1, 4, 5, 7, 4, 3, 7, 3, 2, 0, 0
      },
      5
    },
    { /* 231: err 1! */
      {
        4, 5, 7, 4, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 232: yes */
      {
        4, 5, 7, 4, 3, 0, 3, 2, 2, 6, 1, 5
      },
      6
    },
    { /* 233: err 1! */
      {
        0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 234: err 1! */
      {
        0, 1, 4, 5, 7, 4, 3, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 235: yes */
      {
        4, 5, 7, 4, 0, 4, 0, 0, 0, 0, 0, 0
      },
      3
    },
    { /* 236: yes */
      {
        4, 5, 7, 4, 3, 0, 2, 1, 1, 5, 0, 0
      },
      5
    },
    { /* 237: err 1! */
      {
        0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 238: yes */
      {
        0, 1, 4, 5, 7, 4, 3, 0, 0, 0, 0, 0
      },
      4
    },
    { /* 239: yes */
      {
        4, 5, 7, 4, 0, 4, 0, 0, 0, 0, 0, 0
      },
      3
    },
    { /* 240: yes */
      {
        0, 4, 3, 7, 2, 6, 1, 5, 0, 0, 0, 0
      },
      4
    },
    { /* 241: yes */
      {
        0, 1, 3, 0, 3, 7, 2, 6, 1, 5, 0, 0
      },
      5
    },
    { /* 242: yes */
      {
        0, 1, 0, 4, 3, 7, 2, 6, 2, 1, 0, 0
      },
      5
    },
    { /* 243: yes */
      {
        3, 7, 2, 6, 2, 1, 3, 0, 0, 0, 0, 0
      },
      4
    },
    { /* 244: yes */
      {
        3, 2, 2, 1, 1, 5, 0, 4, 3, 7, 0, 0
      },
      5
    },
    { /* 245: err 1! */
      {
        0, 1, 1, 5, 2, 1, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 246: yes */
      {
        0, 1, 0, 4, 3, 7, 3, 2, 0, 0, 0, 0
      },
      4
    },
    { /* 247: yes */
      {
        3, 2, 3, 0, 3, 7, 0, 0, 0, 0, 0, 0
      },
      3
    },
    { /* 248: yes */
      {
        3, 2, 2, 6, 1, 5, 0, 4, 3, 0, 0, 0
      },
      5
    },
    { /* 249: yes */
      {
        0, 1, 3, 2, 2, 6, 1, 5, 0, 0, 0, 0
      },
      4
    },
    { { 0, 1, 0, 4, 3, 0, 0, 0, 0, 0, 0, 0 }, 0 },
    /* 250: err 1! */ // done
    { /* 251: yes */
      {
        3, 2, 2, 6, 2, 1, 0, 0, 0, 0, 0, 0
      },
      3
    },
    { /* 252: yes */
      {
        0, 4, 3, 0, 2, 1, 1, 5, 0, 0, 0, 0
      },
      4
    },
    { /* 253: yes */
      {
        0, 1, 1, 2, 5, 1, 0, 0, 0, 0, 0, 0
      },
      3
    },
    { /* 254: yes */
      {
        0, 1, 0, 4, 3, 0, 0, 0, 0, 0, 0, 0
      },
      3
    },
    { /* 255: no */
      {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    }
};

static cutting_info Tet_Table[16] = {
    { /* 0000 */
      {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 0001 */
      {
        0, 1, 0, 2, 0, 3, 0, 0, 0, 0, 0, 0
      },
      3
    },
    { /* 0010 */
      {
        0, 1, 1, 3, 1, 2, 0, 0, 0, 0, 0, 0
      },
      3
    },
    { /* 0011 */
      {
        0, 2, 0, 3, 1, 3, 1, 2, 0, 0, 0, 0
      },
      4
    },
    { /* 0100 */
      {
        0, 2, 1, 2, 2, 3, 0, 0, 0, 0, 0, 0
      },
      3
    },
    { /* 0101 */
      {
        0, 1, 1, 2, 2, 3, 0, 3, 0, 0, 0, 0
      },
      4
    },
    { /* 0110 */
      {
        0, 1, 1, 3, 2, 3, 0, 2, 0, 0, 0, 0
      },
      4
    },
    { /* 0111 */
      {
        1, 3, 2, 3, 0, 3, 0, 0, 0, 0, 0, 0
      },
      3
    },
    { /* 1000 */
      {
        2, 3, 1, 3, 0, 3, 0, 0, 0, 0, 0, 0
      },
      3
    },
    { /* 1001 */
      {
        0, 1, 0, 2, 2, 3, 1, 3, 0, 0, 0, 0
      },
      4
    },
    { /* 1010 */
      {
        0, 1, 0, 3, 2, 3, 1, 2, 0, 0, 0, 0
      },
      4
    },
    { /* 1011 */
      {
        0, 2, 3, 2, 2, 1, 0, 0, 0, 0, 0, 0
      },
      3
    },
    { /* 1100 */
      {
        0, 2, 1, 2, 1, 3, 3, 0, 0, 0, 0, 0
      },
      4
    },
    { /* 1101 */
      {
        0, 1, 1, 2, 1, 3, 0, 0, 0, 0, 0, 0
      },
      3
    },
    { /* 1110 */
      {
        0, 3, 0, 2, 0, 1, 0, 0, 0, 0, 0, 0
      },
      3
    },
    { /* 1111 */
      {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    }
};

static cutting_info Pry_Table[32] = /*43210*/
    {
      { /* 0: no  x      00000 */
        {
          0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
        },
        0
      },
      { /* 1: yes x      00001 */
        {
          0, 1, 0, 3, 0, 4, 0, 0, 0, 0, 0, 0
        },
        3
      },
      { /* 2: yes x      00010 */
        {
          1, 4, 1, 2, 0, 1, 0, 0, 0, 0, 0, 0
        },
        3
      },
      { /* 3: yes x      00011 */
        {
          0, 4, 1, 4, 1, 2, 0, 3, 0, 0, 0, 0
        },
        4
      },
      { /* 4: yes x      00100 */
        {
          2, 3, 2, 1, 2, 4, 0, 0, 0, 0, 0, 0
        },
        3
      },
      { /* 5: yes x      00101 */
        {
          0, 3, 0, 4, 0, 1, 2, 1, 2, 4, 2, 3
        },
        6
      },
      { /* 6: yes x      00110 */
        {
          1, 0, 1, 4, 2, 4, 2, 3, 0, 0, 0, 0
        },
        4
      },
      { /* 7: yes x      00111 */
        {
          3, 0, 4, 0, 4, 1, 4, 2, 3, 2, 0, 0
        },
        5
      },
      { /* 8: yes x      01000 */
        {
          2, 3, 3, 4, 3, 0, 0, 0, 0, 0, 0, 0
        },
        3
      },
      { /* 9: yes x      01001 */
        {
          3, 2, 3, 4, 0, 4, 0, 1, 0, 0, 0, 0
        },
        4
      },
      { /* 10: yes x     01010 */
        {
          1, 0, 1, 4, 1, 2, 3, 2, 3, 4, 3, 0
        },
        6
      },
      { /* 11: yes x     01011 */
        {
          4, 3, 4, 0, 4, 1, 2, 1, 2, 3, 0, 0
        },
        5
      },
      { /* 12: yes x     01100 */
        {
          2, 1, 2, 4, 3, 4, 3, 0, 0, 0, 0, 0
        },
        4
      },
      { /* 13: yes x     01101 */
        {
          4, 2, 4, 3, 4, 0, 1, 0, 1, 2, 0, 0
        },
        5
      },
      { /* 14: yes x     01110 */
        {
          4, 1, 4, 2, 4, 3, 0, 3, 0, 1, 0, 0
        },
        5
      },
      { /* 15: yes x     01111 */
        {
          0, 4, 1, 4, 2, 4, 3, 4, 0, 0, 0, 0
        },
        4
      },
      { /* 16: yes x     10000 */
        {
          3, 4, 2, 4, 1, 4, 0, 4, 0, 0, 0, 0
        },
        4
      },
      { /* 17: yes x     10001 */
        {
          4, 3, 4, 2, 4, 1, 0, 1, 0, 3, 0, 0
        },
        5
      },
      { /* 18: yes x     10010 */
        {
          4, 0, 4, 3, 4, 2, 1, 2, 1, 0, 0, 0
        },
        5
      },
      { /* 19: yes x     10011 */
        {
          2, 4, 2, 1, 3, 0, 3, 4, 0, 0, 0, 0
        },
        4
      },
      { /* 20: yes x     10100 */
        {
          4, 1, 4, 0, 4, 3, 2, 3, 2, 1, 0, 0
        },
        5
      },
      { /* 21: yes x     10101 */
        {
          1, 2, 1, 4, 1, 0, 3, 0, 3, 4, 3, 2
        },
        6
      },
      { /* 22: yes x     10110 */
        {
          3, 4, 3, 2, 0, 1, 0, 4, 0, 0, 0, 0
        },
        4
      },
      { /* 23: yes x     10111 */
        {
          3, 2, 3, 0, 3, 4, 0, 0, 0, 0, 0, 0
        },
        3
      },
      { /* 24: yes x     11000 */
        {
          4, 0, 3, 0, 3, 2, 4, 2, 4, 1, 0, 0
        },
        5
      },
      { /* 25: yes x     11001 */
        {
          2, 3, 2, 4, 1, 4, 0, 1, 0, 0, 0, 0
        },
        4
      },
      { /* 26: yes x     11010 */
        {
          0, 1, 0, 4, 0, 3, 2, 3, 2, 4, 2, 1
        },
        6
      },
      { /* 27: yes x     11011 */
        {
          2, 3, 2, 4, 2, 1, 0, 0, 0, 0, 0, 0
        },
        3
      },
      { /* 28: yes x     11100 */
        {
          1, 2, 1, 4, 4, 0, 0, 3, 0, 0, 0, 0
        },
        4
      },
      { /* 29: yes x     11101 */
        {
          1, 4, 1, 0, 2, 1, 0, 0, 0, 0, 0, 0
        },
        3
      },
      { /* 30: yes x     11110 */
        {
          0, 1, 0, 4, 0, 3, 0, 0, 0, 0, 0, 0
        },
        3
      },
      { /* 31: no  x     11111 */
        {
          0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
        },
        0
      }
    };

static cutting_info Psm_Table[64] = {
    { /* 0: no         00000000 */
      {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 1: yes        00000001 */
      {
        0, 1, 0, 2, 0, 3, 0, 0, 0, 0, 0, 0
      },
      3
    },
    { /* 2: yes        00000010 */
      {
        1, 4, 1, 2, 0, 1, 0, 0, 0, 0, 0, 0
      },
      3
    },
    { /* 3: yes        00000011 */
      {
        0, 2, 0, 3, 1, 4, 1, 2, 0, 0, 0, 0
      },
      4
    },
    { /* 4: yes        00000100 */
      {
        2, 5, 0, 2, 1, 2, 0, 0, 0, 0, 0, 0
      },
      3
    },
    { /* 5: yes        00000101 */
      {
        0, 1, 1, 2, 2, 5, 0, 3, 0, 0, 0, 0
      },
      4
    },
    { /* 6: yes        00000110 */
      {
        0, 1, 1, 4, 2, 5, 0, 2, 0, 0, 0, 0
      },
      4
    },
    { /* 7: yes        00000111 */
      {
        0, 3, 1, 4, 2, 5, 0, 0, 0, 0, 0, 0
      },
      3
    },
    { /* 8: yes        00001000 */
      {
        0, 3, 3, 5, 3, 4, 0, 0, 0, 0, 0, 0
      },
      3
    },
    { /* 9: yes        00001001 */
      {
        3, 5, 3, 4, 0, 1, 0, 2, 0, 0, 0, 0
      },
      4
    },
    { /* 10: yes       00001010 */
      {
        1, 4, 1, 2, 0, 1, 0, 3, 3, 5, 3, 4
      },
      6
    },
    { /* 11: yes       00001011 */
      {
        0, 2, 3, 5, 3, 4, 1, 4, 1, 2, 0, 0
      },
      5
    },
    { /* 12: yes       00001100 */
      {
        3, 5, 3, 4, 0, 3, 0, 2, 1, 2, 2, 5
      },
      6
    },
    { /* 13: yes       00001101 */
      {
        2, 5, 3, 5, 3, 4, 0, 1, 1, 2, 0, 0
      },
      5
    },
    { /* 14: no        00001110 */
      {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 15: yes       00001111 */
      {
        2, 5, 3, 5, 3, 4, 1, 4, 0, 0, 0, 0
      },
      4
    },
    { /* 16: yes       00010000 */
      {
        1, 4, 3, 4, 4, 5, 0, 0, 0, 0, 0, 0
      },
      3
    },
    { /* 17: yes       00010001 */
      {
        0, 1, 0, 2, 0, 3, 3, 4, 4, 5, 1, 4
      },
      6
    },
    { /* 18: yes       00010010 */
      {
        0, 1, 3, 4, 4, 5, 1, 2, 0, 0, 0, 0
      },
      4
    },
    { /* 19: yes       00010011 */
      {
        0, 3, 3, 4, 4, 5, 1, 2, 0, 2, 0, 0
      },
      5
    },
    { /* 20: yes       00010100 */
      {
        1, 4, 3, 4, 4, 5, 2, 5, 0, 2, 1, 2
      },
      6
    },
    { /* 21: yes       00010101 */
      {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 22: yes       00010110 */
      {
        0, 1, 3, 4, 4, 5, 2, 5, 0, 2, 0, 0
      },
      5
    },
    { /* 23: yes       00010111 */
      {
        0, 3, 3, 4, 4, 5, 2, 5, 0, 0, 0, 0
      },
      4
    },
    { /* 24: yes       00011000 */
      {
        3, 5, 4, 5, 1, 4, 0, 3, 0, 0, 0, 0
      },
      4
    },
    /*{ { 0,2, 3,4, 4,5, 1,4, 0,1, 0,0 }, 5},  25: yes        00011000 */
    { /* 25: yes    00011001 */
      {
        1, 0, 1, 4, 5, 4, 5, 3, 2, 0, 0, 0
      },
      5
    },
    { /* 26: yes       00011010 */
      {
        0, 1, 0, 3, 3, 5, 4, 5, 1, 2, 0, 0
      },
      5
    },
    { /* 27: yes       00011011 */
      {
        3, 5, 4, 5, 1, 2, 0, 2, 0, 0, 0, 0
      },
      4
    },
    { /* 28: no        00011100 */
      {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
      },
      0
    },
    { /* 29: yes       00011101 */
      {
        2, 5, 3, 5, 4, 5, 1, 4, 0, 1, 1, 2
      },
      6
    },
    { { 0, 3, 0, 1, 0, 2, 2, 5, 4, 5, 3, 5 }, 6 },
    { { 2, 5, 3, 5, 4, 5, 0, 0, 0, 0, 0, 0 }, 3 },
    { { 2, 5, 4, 5, 3, 5, 0, 0, 0, 0, 0, 0 }, 3 },
    { { 0, 3, 0, 1, 0, 2, 2, 5, 4, 5, 3, 5 }, 6 },
    { { 1, 2, 0, 1, 1, 4, 4, 5, 3, 5, 2, 5 }, 6 },
    { { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 0 },
    { { 0, 2, 1, 2, 4, 5, 3, 5, 0, 0, 0, 0 }, 4 },
    { { 1, 2, 4, 5, 3, 5, 0, 3, 0, 1, 0, 0 }, 5 },
    { { 0, 1, 1, 4, 4, 5, 3, 5, 0, 2, 0, 0 }, 5 },
    { { 0, 3, 1, 4, 4, 5, 3, 5, 0, 0, 0, 0 }, 4 },
    { { 2, 5, 4, 5, 3, 4, 0, 3, 0, 0, 0, 0 }, 4 },
    { { 0, 2, 2, 5, 4, 5, 3, 4, 0, 1, 0, 0 }, 5 },
    { { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 0 },
    { { 1, 2, 0, 2, 2, 5, 4, 5, 3, 4, 1, 4 }, 6 },
    { { 0, 2, 1, 2, 4, 5, 3, 4, 0, 3, 0, 0 }, 5 },
    { { 1, 2, 4, 5, 3, 4, 0, 1, 0, 0, 0, 0 }, 4 },
    { { 0, 1, 0, 2, 0, 3, 3, 4, 4, 5, 1, 4 }, 6 },
    { { 1, 4, 5, 4, 4, 3, 0, 0, 0, 0, 0, 0 }, 3 },
    { { 1, 4, 3, 4, 3, 5, 2, 5, 0, 0, 0, 0 }, 4 },
    { { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 0 },
    { { 1, 2, 0, 1, 3, 4, 3, 5, 2, 5, 0, 0 }, 5 },
    { { 2, 5, 1, 2, 0, 2, 0, 3, 3, 4, 3, 5 }, 6 },
    { { 1, 2, 1, 4, 3, 4, 3, 5, 0, 2, 0, 0 }, 5 },
    { { 1, 4, 1, 2, 0, 1, 0, 3, 3, 5, 3, 4 }, 6 },
    { { 3, 4, 3, 5, 0, 2, 0, 1, 0, 0, 0, 0 }, 4 },
    { { 0, 3, 3, 4, 3, 5, 0, 0, 0, 0, 0, 0 }, 3 },
    { { 0, 3, 2, 5, 1, 4, 0, 0, 0, 0, 0, 0 }, 3 },
    { { 0, 2, 2, 5, 1, 4, 0, 1, 0, 0, 0, 0 }, 4 },
    { { 0, 1, 0, 3, 2, 5, 1, 2, 0, 0, 0, 0 }, 4 },
    { { 2, 5, 1, 2, 0, 2, 0, 0, 0, 0, 0, 0 }, 3 },
    { { 0, 3, 0, 2, 1, 2, 1, 4, 0, 0, 0, 0 }, 4 },
    { { 1, 4, 0, 1, 1, 2, 0, 0, 0, 0, 0, 0 }, 3 },
    { { 0, 1, 0, 3, 0, 2, 0, 0, 0, 0, 0, 0 }, 3 },
    { { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 0 }
};

static cutting_info *Cutting_Info[8] = { 0, 0, 0, 0, Tet_Table, Pry_Table, Psm_Table, Hex_Table };

static int Triangle_table[8][4] = {
    { 0, 0, 0, 0 },
    { 0, 1, 2, 1 },
    { 1, 0, 2, 1 },
    { 2, 1, 0, 1 },
    { 2, 0, 1, 1 },
    { 1, 0, 2, 1 },
    { 0, 1, 2, 1 },
    { 0, 0, 0, 0 }
};
}
#endif