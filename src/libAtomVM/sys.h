/***************************************************************************
 *   Copyright 2017 by Davide Bettio <davide@uninstall.it>                 *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU Lesser General Public License as        *
 *   published by the Free Software Foundation; either version 2 of the    *
 *   License, or (at your option) any later version.                       *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA .        *
 ***************************************************************************/

#ifndef _SYS_H_
#define _SYS_H_

#include "linkedlist.h"

typedef void (*event_handler_t)(void *data);

typedef struct EventListener {
    struct ListHead listeners_list_head;

    int expires;
    struct timespec expiral_timestamp;

    event_handler_t handler;
    void *data;
    int fd;
} EventListener;

extern void sys_waitevents(struct ListHead *listeners_list);
extern void sys_set_timestamp_from_relative_to_abs(struct timespec *t, int32_t millis);

#endif