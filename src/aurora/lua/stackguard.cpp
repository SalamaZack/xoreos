/* xoreos - A reimplementation of BioWare's Aurora engine
 *
 * xoreos is the legal property of its developers, whose names
 * can be found in the AUTHORS file distributed with this source
 * distribution.
 *
 * xoreos is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 3
 * of the License, or (at your option) any later version.
 *
 * xoreos is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with xoreos. If not, see <http://www.gnu.org/licenses/>.
 */

/** @file
 *  Lua stack guard.
 *  It's a helper class for storing and restoring the top position of a Lua stack.
 *  A guard stores the top at the construction and restores it at the end of a scope.
 */

#include "src/aurora/lua/stackguard.h"
#include "src/aurora/lua/stack.h"

namespace Aurora {

namespace Lua {

StackGuard::StackGuard(const Stack &stack) : _state(stack.getLuaState()),
	_top(lua_gettop(&_state)) {

}

StackGuard::StackGuard(lua_State &state) : _state(state),
	_top(lua_gettop(&_state)) {
}

StackGuard::~StackGuard() {
	lua_settop(&_state, _top);
}

} // End of namespace Lua

} // End of namespace Aurora
