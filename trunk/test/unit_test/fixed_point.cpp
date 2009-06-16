/******************************************************************************/
/*                                                                            */
/*  Copyright (c) 2007-2009: Peter Schregle,                                  */
/*                           Impuls computergestützte Bildanalyse GmbH.       */
/*  All rights reserved.                                                      */  
/*                                                                            */
/*  This file is part of the Fixed Point Math Library.                        */
/*                                                                            */
/*  Redistribution of the Fixed Point Math Library and use in source and      */
/*  binary forms, with or without modification, are permitted provided that   */
/*  the following conditions are met:                                         */
/*  1. Redistributions of source code must retain the above copyright notice, */
/*     this list of conditions and the following disclaimer.                  */
/*  2. Redistributions in binary form must reproduce the above copyright      */
/*     notice, this list of conditions and the following disclaimer in the    */
/*     documentation and/or other materials provided with the distribution.   */
/*  3. Neither the name of Impuls computergestützte Bildanalyse GmbH nor the  */
/*     names of its contributors may be used to endorse or promote products   */
/*     derived from this software without specific prior written permission.  */
/*                                                                            */
/*  THIS SOFTWARE IS PROVIDED BY IMPULS COMPUTERGESTÜTZTE BILDANALYSE GMBH    */
/*  AND CONTRIBUTORS “AS IS” AND ANY EXPRESS OR IMPLIED WARRANTIES,           */ 
/*  INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY  */
/*  AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL    */
/*  IMPULS COMPUTERGESTÜTZTE BILDANALYSE GMBH OR CONTRIBUTORS BE LIABLE FOR   */
/*  ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL    */
/*  DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS   */
/*  OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)     */
/*  HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,       */
/*  STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN  */
/*  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE           */
/*  POSSIBILITY OF SUCH DAMAGE.                                               */
/*                                                                            */
/******************************************************************************/


#include <boost/test/unit_test.hpp>

#include "..\..\include\fpml\fixed_point.h"

BOOST_AUTO_TEST_SUITE( fixed_point )


BOOST_AUTO_TEST_CASE( construction )
{
	fpml::fixed_point<int, 16> fp0(0);
	BOOST_CHECK( (int)fp0 == 0 );

	fpml::fixed_point<int, 16> fp1((signed char)-128);
	BOOST_CHECK( (signed char)fp1 == -128 );

	fpml::fixed_point<int, 16> fp2((unsigned char)127);
	BOOST_CHECK( (unsigned char)fp2 == 127 );

	fpml::fixed_point<int, 16> fp3((signed short)-32768);
	BOOST_CHECK( (signed short)fp3 == -32768 );

	fpml::fixed_point<int, 16> fp4((unsigned short)32767);
	BOOST_CHECK( (unsigned short)fp4 == 32767 );

	fpml::fixed_point<int, 16> fp5((signed int)-32768);
	BOOST_CHECK( (signed int)fp5 == -32768 );

	fpml::fixed_point<int, 16> fp6((unsigned int)32767);
	BOOST_CHECK( (unsigned int)fp6 == 32767 );

	fpml::fixed_point<int, 16> fp7((float)-1.5);
	BOOST_CHECK( (float)fp7 == -1.5 );

	fpml::fixed_point<int, 16> fp8((float)1.5);
	BOOST_CHECK( (float)fp8 == 1.5 );

	fpml::fixed_point<int, 16> fp9((double)-1.5);
	BOOST_CHECK( (double)fp9 == -1.5 );

	fpml::fixed_point<int, 16> fp10((double)1.5);
	BOOST_CHECK( (double)fp10 == 1.5 );

	fpml::fixed_point<int, 16> fp11((long double)-1.5);
	BOOST_CHECK( (long double)fp11 == -1.5 );

	fpml::fixed_point<int, 16> fp12((long double)1.5);
	BOOST_CHECK( (long double)fp12 == 1.5 );
}

BOOST_AUTO_TEST_CASE( equality )
{
	fpml::fixed_point<int, 16> fp0(0);
	fpml::fixed_point<int, 16> fp1((signed char)-128);
	fpml::fixed_point<int, 16> fp2((unsigned char)127);
	fpml::fixed_point<int, 16> fp3((signed short)-32768);
	fpml::fixed_point<int, 16> fp4((unsigned short)32767);
	fpml::fixed_point<int, 16> fp5((signed int)-32768);
	fpml::fixed_point<int, 16> fp6((unsigned int)32767);
	fpml::fixed_point<int, 16> fp7((float)-1.5);
	fpml::fixed_point<int, 16> fp8((float)1.5);
	fpml::fixed_point<int, 16> fp9((double)-1.5);
	fpml::fixed_point<int, 16> fp10((double)1.5);
	fpml::fixed_point<int, 16> fp11((long double)-1.5);
	fpml::fixed_point<int, 16> fp12((long double)1.5);

	bool same = fp3 == fp5 && fp4 == fp6 && fp7 == fp9 && fp9 == fp11 &&
		fp8 == fp10 && fp10 == fp12;
	bool notsame = fp1 != fp2 && fp3 != fp4 && fp5 != fp6 && fp7 != fp8 &&
		fp9 != fp10 && fp11 != fp12;

	BOOST_CHECK( same );
	BOOST_CHECK( notsame );
}

BOOST_AUTO_TEST_CASE( comparison )
{
	fpml::fixed_point<int, 16> fp0(0);
	fpml::fixed_point<int, 16> fp1((signed char)-128);
	fpml::fixed_point<int, 16> fp2((unsigned char)127);
	fpml::fixed_point<int, 16> fp3((signed short)-32768);
	fpml::fixed_point<int, 16> fp4((unsigned short)32767);
	fpml::fixed_point<int, 16> fp5((signed int)-32768);
	fpml::fixed_point<int, 16> fp6((unsigned int)32767);
	fpml::fixed_point<int, 16> fp7((float)-1.5);
	fpml::fixed_point<int, 16> fp8((float)1.5);
	fpml::fixed_point<int, 16> fp9((double)-1.5);
	fpml::fixed_point<int, 16> fp10((double)1.5);
	fpml::fixed_point<int, 16> fp11((long double)-1.5);
	fpml::fixed_point<int, 16> fp12((long double)1.5);

	bool smaller = fp1 < fp2;
	bool bigger = fp2 > fp1;
	bool notsmaller = !(fp4 < fp3);
	bool notbigger = !(fp3 > fp4);

	BOOST_CHECK( smaller );
	BOOST_CHECK( bigger );
	BOOST_CHECK( notsmaller );
	BOOST_CHECK( notbigger );
}

BOOST_AUTO_TEST_CASE( absolute )
{
	double a=(std::numeric_limits<fpml::fixed_point<int, 16>>::min)(); 
	a += 1;
	while (a<=(double)(std::numeric_limits<fpml::fixed_point<int, 16>>::max)()) 
	{
		fpml::fixed_point<int, 16> b = fabs((fpml::fixed_point<int, 16>)a);

		BOOST_CHECK( (double)b == fabs(a) );
		a += .5;
	}
}

BOOST_AUTO_TEST_CASE( square_root )
{
	for (double a=0; 
		a<=(double)(std::numeric_limits<fpml::fixed_point<int, 16>>::max)(); 
		a += .5)
	{
		fpml::fixed_point<int, 16> b = sqrt((fpml::fixed_point<int, 16>)a);

		fpml::fixed_point<int, 16> bb = (double)b;
		fpml::fixed_point<int, 16> sqrta = sqrt(a);

		BOOST_CHECK( (fpml::fixed_point<int, 16>)(double)b == (fpml::fixed_point<int, 16>)sqrt(a) );
	}
}

BOOST_AUTO_TEST_SUITE_END()

