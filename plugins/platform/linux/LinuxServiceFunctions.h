/*
 * LinuxServiceFunctions.h - declaration of LinuxServiceFunctions class
 *
 * Copyright (c) 2017 Tobias Junghans <tobydox@users.sf.net>
 *
 * This file is part of Veyon - http://veyon.io
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this program (see COPYING); if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 *
 */

#ifndef LINUX_SERVICE_FUNCTIONS_H
#define LINUX_SERVICE_FUNCTIONS_H

#include "PlatformServiceFunctions.h"

// clazy:excludeall=copyable-polymorphic

class LinuxServiceFunctions : public PlatformServiceFunctions
{
public:
	bool isRunning( const QString& serviceName ) override;
	bool start( const QString& serviceName ) override;
	bool stop( const QString& serviceName ) override;
};

#endif // LINUX_SERVICE_FUNCTIONS_H
