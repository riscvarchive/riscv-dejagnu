## Process this file with automake to produce Makefile.in

# Copyright (c) 2001 Clifton Labs, Inc
# All rights reserved.

# CLIFTON LABS MAKES NO REPRESENTATIONS OR WARRANTIES ABOUT THE
# SUITABILITY OF THE SOFTWARE, EITHER EXPRESS OR IMPLIED, INCLUDING BUT
# NOT LIMITED TO THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR
# A PARTICULAR PURPOSE, OR NON-INFRINGEMENT.  CLIFTON LABS SHALL NOT BE
# LIABLE FOR ANY DAMAGES SUFFERED BY LICENSEE AS A RESULT OF USING,
# RESULT OF USING, MODIFYING OR DISTRIBUTING THIS SOFTWARE OR ITS
# DERIVATIVES.

# By using or copying this Software, Licensee agrees to abide by the
# intellectual property laws, and all other applicable laws of the U.S.,
# and the terms of this license.

# You may modify, distribute, and use the software contained in this
# package under the terms of the "GNU LIBRARY GENERAL PUBLIC LICENSE"
# version 2, June 1991. A copy of this license agreement can be found in
# the file "LGPL", distributed with this archive.

# Author: Philip A. Wilsey	philip.wilsey@ieee.org

# ------------------------------------------------------------------------

AUTOMAKE_OPTIONS = dejagnu
RUNTESTDEFAULTFLAGS = -v -v

EXTRA_DIST = \
	config/base-config.exp \
	config/default.exp \
	config/gnu.exp \
	config/helloworld-driver.exp \
	config/helloworld-lib.exp \
	config/helloworld-torture.exp \
	config/unix.exp \
	helloworld.test1/helloworld.test1-1/test1-1.exp \
	helloworld.test1/test1.exp \
	helloworld.test2/test2.exp \
	helloworld.test2/test3.exp \
	helloworld.test3/config/config.exp \
	helloworld.test3/lib/lib.exp \
	helloworld.test3/non_compliant_dir_name/non_compliant.exp \
	lib/default.exp \
	lib/gnu.exp \
	lib/helloworld-driver.exp \
	lib/helloworld-lib.exp \
	lib/helloworld-torture.exp \
	lib/helloworld.exp \
	lib/unix.exp \
	testsuite.exp \
	site.exp

# hello_AUTOMAKE_OPTIONS = dejagnu
# hello_RUNTESTDEFAULTFLAGS = --srcdir $$srcdir/testsuite testsuite.exp

check-demo:
	runtest testsuite.exp
