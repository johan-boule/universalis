// This source is free software ; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation ; either version 2, or (at your option) any later version.
// copyright 2006-2008 members of the psycle project http://psycle.sourceforge.net ; johan boule <bohan@jabber.org>

///\interface universalis::processor::atomic::compare_and_swap
#pragma once
#include <diversalis/compiler.hpp>
#if defined DIVERSALIS__COMPILER__GNU && DIVERSALIS__COMPILER__VERSION >= 40100 // 4.1.0
	// gcc's __sync_* built-in functions documented at http://gcc.gnu.org/onlinedocs/gcc-4.1.0/gcc/Atomic-Builtins.html
#else
	#include <glib/gatomic.h>
#endif
namespace universalis { namespace processor { namespace atomic {

// see c++ standard http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2006/n2047.html
// see apache portable runtime http://svn.apache.org/viewvc/apr/apr/trunk/atomic
// see apache harmony atomic http://svn.apache.org/viewvc/harmony/enhanced/drlvm/trunk/vm/port/include/port_atomic.h
// see apache harmony barrier http://svn.apache.org/viewvc/harmony/enhanced/drlvm/trunk/vm/port/include/port_barriers.h
// see glibc */bits/atomic.h at http://sources.redhat.com/cgi-bin/cvsweb.cgi/libc/sysdeps/?cvsroot=glibc
// see glib atomic http://svn.gnome.org/viewvc/glib/trunk/glib/gatomic.c?view=markup
// see glib/gstreamer ring buffer http://webcvs.freedesktop.org/gstreamer/gst-plugins-base/gst-libs/gst/audio/gstringbuffer.c
// see portaudio memory barrier http://portaudio.com/trac/browser/portaudio/trunk/src/common/pa_memorybarrier.h
// see portaudio ring buffer    http://portaudio.com/trac/browser/portaudio/trunk/src/common/pa_ringbuffer.c
// see liblf data structures http://www.audiomulch.com/~rossb/code/lockfree/liblfds
// see liblf data structures http://tech.groups.yahoo.com/group/liblf-dev
// see microsoft/intel _Interlocked* intrinsics

/// atomic compare and swap with full memory barrier.
/// does not fail spuriously.
template<typename Value>
bool inline compare_and_swap(Value * address, Value old_value, Value new_value) {
	#if defined DIVERSALIS__COMPILER__GNU && DIVERSALIS__COMPILER__VERSION >= 40100 // 4.1.0
		return __sync_bool_compare_and_swap(address, old_value, new_value);
	#else
		// no return statement to error on purpose -- see template specialisations below
	#endif
}

#if !defined DIVERSALIS__COMPILER__GNU || DIVERSALIS__COMPILER__VERSION < 40100 // 4.1.0
	template<>
	bool inline compare_and_swap< ::gpointer>(::gpointer * address, ::gpointer old_value, ::gpointer new_value) {
		return ::g_atomic_pointer_compare_and_exchange(address, old_value, new_value);
	}

	template<>
	bool inline compare_and_swap< ::gint>(::gint * address, ::gint old_value, ::gint new_value) {
		return ::g_atomic_int_compare_and_exchange(address, old_value, new_value);
	}
#endif

}}}
