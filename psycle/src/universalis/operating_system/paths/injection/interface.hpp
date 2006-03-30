// This source is free software ; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation ; either version 2, or (at your option) any later version.
// Copyright (C) 1999-2006 Johan Boule <bohan@jabber.org>
// Copyright (C) 2004-2006 Psycledelics http://psycle.pastnotecut.org

///\interface universalis::operating_system::paths

using boost::filesystem::path;
path const UNIVERSALIS__COMPILER__DYNAMIC_LINK & bin();
path const UNIVERSALIS__COMPILER__DYNAMIC_LINK & lib();
path const UNIVERSALIS__COMPILER__DYNAMIC_LINK & share();
path const UNIVERSALIS__COMPILER__DYNAMIC_LINK & var();
path const UNIVERSALIS__COMPILER__DYNAMIC_LINK & etc();
path const UNIVERSALIS__COMPILER__DYNAMIC_LINK & home();
namespace package
{
	std::string const UNIVERSALIS__COMPILER__DYNAMIC_LINK & name();
	namespace version
	{
		std::string const UNIVERSALIS__COMPILER__DYNAMIC_LINK & string();
		/// it couldn't be named just 'major', because 'major' is a #define in <sys/sysmacros.h> used for device nodes and <cstdint> includes it.
		unsigned int UNIVERSALIS__COMPILER__DYNAMIC_LINK major_number() throw();
		/// it couldn't be named just 'minor', because 'minor' is a #define in <sys/sysmacros.h> used for device nodes and <cstdint> includes it.
		unsigned int UNIVERSALIS__COMPILER__DYNAMIC_LINK minor_number() throw();
		unsigned int UNIVERSALIS__COMPILER__DYNAMIC_LINK patch_number() throw();
	}
	path const UNIVERSALIS__COMPILER__DYNAMIC_LINK & lib();
	path const UNIVERSALIS__COMPILER__DYNAMIC_LINK & share();
	path const UNIVERSALIS__COMPILER__DYNAMIC_LINK & pixmaps();
	path const UNIVERSALIS__COMPILER__DYNAMIC_LINK & doc();
	path const UNIVERSALIS__COMPILER__DYNAMIC_LINK & var();
	path const UNIVERSALIS__COMPILER__DYNAMIC_LINK & log();
	path const UNIVERSALIS__COMPILER__DYNAMIC_LINK & etc();
	path const UNIVERSALIS__COMPILER__DYNAMIC_LINK & home();
}