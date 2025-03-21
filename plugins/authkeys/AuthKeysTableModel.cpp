/*
 * AuthKeysTableModel.cpp - implementation of AuthKeysTableModel class
 *
 * Copyright (c) 2018-2025 Tobias Junghans <tobydox@veyon.io>
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

#include "AuthKeysTableModel.h"
#include "AuthKeysManager.h"

AuthKeysTableModel::AuthKeysTableModel( AuthKeysManager& manager, QObject* parent ) :
	QAbstractTableModel( parent ),
	m_manager( manager )
{
}



void AuthKeysTableModel::reload()
{
	beginResetModel();

	m_keys = m_manager.listKeys();

	endResetModel();
}



int AuthKeysTableModel::columnCount( const QModelIndex& parent ) const
{
	Q_UNUSED(parent)

	return ColumnCount;
}



int AuthKeysTableModel::rowCount( const QModelIndex& parent ) const
{
	Q_UNUSED(parent)

	return m_keys.size();
}



QVariant AuthKeysTableModel::data( const QModelIndex& index, int role ) const
{
	if( index.isValid() == false || role != Qt::DisplayRole )
	{
		return {};
	}

	const auto& key = m_keys[index.row()];

	switch( index.column() )
	{
	case ColumnKeyName: return key.split( QLatin1Char('/') ).value( 0 );
	case ColumnKeyType: return key.split( QLatin1Char('/') ).value( 1 );
	case ColumnAccessGroup: return m_manager.accessGroup( key );
	case ColumnKeyPairID: return m_manager.keyPairId( key );
	default: break;
	}

	return {};
}



QVariant AuthKeysTableModel::headerData( int section, Qt::Orientation orientation, int role ) const
{
	if( orientation != Qt::Horizontal || role != Qt::DisplayRole )
	{
		return {};
	}

	switch( section )
	{
	case ColumnKeyName: return tr( "Name" );
	case ColumnKeyType: return tr( "Type" );
	case ColumnAccessGroup: return tr( "Access group");
	case ColumnKeyPairID: return tr( "Pair ID");
	default:
		break;
	}

	return {};
}
