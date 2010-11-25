// Cyphesis Online RPG Server and AI Engine
// Copyright (C) 2001 Alistair Riddoch
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software Foundation,
// Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA

#include "server/TeleportState.h"

/// \brief Constructor
TeleportState::TeleportState(time_t time) : m_isMind(false),
                                        m_state(TELEPORT_NONE),
                                        m_teleportTime(time)
{
}

/// \brief Set the teleport state as requested
void TeleportState::setRequested()
{
    m_state = TELEPORT_REQUESTED;
}

/// \brief Set the teleport state as created
void TeleportState::setCreated()
{
    m_state = TELEPORT_CREATED;
}

/// \brief Set the teleport possess key
void TeleportState::setKey(const std::string & key)
{
    m_possessKey = key;
    m_isMind = true;
}

/// \brief Check if the teleported entity has been create on the remote end
///
/// @return Boolean whether entity has been created or not
bool TeleportState::isCreated() const
{
    return (m_state == TELEPORT_CREATED);
}

/// \brief Check if the teleport state is 'currently requesting'
///
/// @return Whether the state is requesting or not
bool TeleportState::isRequested() const
{
    return (m_state == TELEPORT_REQUESTED);
}

/// \brief Check if a teleported entity has an external mind
///
/// @return Whether the teleported entity has an external mind
bool TeleportState::isMind() const
{
    return m_isMind;
}

/// \brief Get the possess key generated for this teleport
///
/// @return The randomly generated possess key for this teleport
const std::string & TeleportState::getPossessKey() const
{
    return m_possessKey;
}

time_t TeleportState::getCreateTime() const
{
    return m_teleportTime;
}
