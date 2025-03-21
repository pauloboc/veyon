/*
 * ServiceControlCommands.cpp - implementation of ServiceControlCommands class
 *
 * Copyright (c) 2017-2025 Tobias Junghans <tobydox@veyon.io>
 *
 * This file is part of Veyon - https://veyon.io
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

#include "CommandLineIO.h"
#include "ServiceControlCommands.h"
#include "VeyonServiceControl.h"

ServiceControlCommands::ServiceControlCommands( QObject* parent ) :
	QObject( parent ),
	m_commands( {
{ QStringLiteral("register"), tr( "Register Veyon Service" ) },
{ QStringLiteral("unregister"), tr( "Unregister Veyon Service" ) },
{ QStringLiteral("start"), tr( "Start Veyon Service" ) },
{ QStringLiteral("stop"), tr( "Stop Veyon Service" ) },
{ QStringLiteral("restart"), tr( "Restart Veyon Service" ) },
{ QStringLiteral("status"), tr( "Query status of Veyon Service" ) },
				} )
{
}



CommandLinePluginInterface::RunResult ServiceControlCommands::handle_register( const QStringList& arguments )
{
	Q_UNUSED(arguments)

	VeyonServiceControl serviceControl;
	serviceControl.registerService();

	return serviceControl.isServiceRegistered() ? Successful : Failed;
}



CommandLinePluginInterface::RunResult ServiceControlCommands::handle_unregister( const QStringList& arguments )
{
	Q_UNUSED(arguments)
	VeyonServiceControl serviceControl;
	serviceControl.unregisterService();

	return serviceControl.isServiceRegistered() ? Failed : Successful;
}



CommandLinePluginInterface::RunResult ServiceControlCommands::handle_start( const QStringList& arguments )
{
	Q_UNUSED(arguments)

	VeyonServiceControl serviceControl;
	serviceControl.startService();

	return serviceControl.isServiceRunning() ? Successful : Failed;
}



CommandLinePluginInterface::RunResult ServiceControlCommands::handle_stop( const QStringList& arguments )
{
	Q_UNUSED(arguments)

	VeyonServiceControl serviceControl;
	serviceControl.stopService();

	return serviceControl.isServiceRunning() ? Failed : Successful;
}



CommandLinePluginInterface::RunResult ServiceControlCommands::handle_restart( const QStringList& arguments )
{
	handle_stop( arguments );
	return handle_start( arguments );
}



CommandLinePluginInterface::RunResult ServiceControlCommands::handle_status( const QStringList& arguments )
{
	Q_UNUSED(arguments)

	if( VeyonServiceControl().isServiceRunning() )
	{
		CommandLineIO::print( tr( "Service is running" ) );
	}
	else
	{
		CommandLineIO::print( tr( "Service is not running" ) );
	}

	return NoResult;
}
