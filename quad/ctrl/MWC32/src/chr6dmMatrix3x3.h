/*
  June 2012

  BaseFlightPlus Rev -

  An Open Source STM32 Based Multicopter

  Includes code and/or ideas from:

  1)AeroQuad
  2)BaseFlight
  3)CH Robotics
  4)MultiWii
  5)S.O.H. Madgwick

  Designed to run on Naze32 Flight Control Board

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

/* ------------------------------------------------------------------------------
  File: matrix3x3.h
  Author: CH Robotics
  Version: 1.0

  Description: Functions for performing operations on 3x3 matrices
------------------------------------------------------------------------------ */

#pragma once

// Structure for holding 3x3 matrices
typedef struct _fmat3x3 {
    float data[3][3];
} fmat3x3;

// Structure for holding 3-element vectors
typedef struct _fvect3x1 {
    float data[3];
} fvect3x1;

// Function declarations
int MatAdd3x3(fmat3x3 * src1, fmat3x3 * src2, fmat3x3 * dest);
int MatMult3x3(fmat3x3 * src1, fmat3x3 * src2, fmat3x3 * dest);
int MatInv3x3(fmat3x3 * src, fmat3x3 * dest);
int MatVectMult3(fmat3x3 * matrix, fvect3x1 * vector, fvect3x1 * dest);
float MatDet3x3(fmat3x3 * src);
int MatTrans3x3(fmat3x3 * src, fmat3x3 * dest);
int ScalarMatMult3x3(float T, fmat3x3 * src, fmat3x3 * dest);
void CreateIdentity3x3(fmat3x3 * dest);
void MatZero3x3(fmat3x3 * dest);
void MatCopy3x3(fmat3x3 * src, fmat3x3 * dest);
