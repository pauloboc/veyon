/*
 * ServiceControlCommands.h - declaration of ServiceControlCommands class
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

#pragma once

#include "CommandLinePluginInterface.h"

class ServiceControlCommands : public QObject, CommandLinePluginInterface, PluginInterface
{
	Q_OBJECT
	Q_INTERFACES(PluginInterface CommandLinePluginInterface)
public:
	explicit ServiceControlCommands( QObject* parent = nullptr );
	~ServiceControlCommands() override = default;

	Plugin::Uid uid() const override
	{
		return Plugin::Uid{ QStringLiteral("b47bcae0-24ff-4bf5-869c-484d64af5c4c") };
	}

	QVersionNumber version() const override
	{
		return QVersionNumber( 1, 1 );
	}

	QString name() const override
	{
		return QStringLiteral( "ServiceControl" );
	}

	QString description() const override
	{
		return tr( "Configure and control Veyon service" );
	}

	QString vendor() const override
	{
		return QStringLiteral( "Veyon Community" );
	}

	QString copyright() const override
	{
		return QStringLiteral( "Tobias Junghans" );
	}

	QString commandLineModuleName() const override
	{
		return QStringLiteral( "service" );
	}

	QString commandLineModuleHelp() const override
	{
		return tr( "Commands for configuring and controlling Veyon Service" );
	}

	QStringList commands() const override
	{
		return m_commands.keys();
	}

	QString commandHelp( const QString& command ) const override
	{
		return m_commands.value( command );
	}

public Q_SLOTS:
	CommandLinePluginInterface::RunResult handle_register( const QStringList& arguments );
	CommandLinePluginInterface::RunResult handle_unregister( const QStringList& arguments );
	CommandLinePluginInterface::RunResult handle_start( const QStringList& arguments );
	CommandLinePluginInterface::RunResult handle_stop( const QStringList& arguments );
	CommandLinePluginInterface::RunResult handle_restart( const QStringList& arguments );
	CommandLinePluginInterface::RunResult handle_status( const QStringList& arguments );

private:
	QMap<QString, QString> m_commands;

};
