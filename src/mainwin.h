/***************************************************************************
 *   Copyright (C) 2007 by PCMan (Hong Jen Yee)  pcman.tw@gmail.com        *
 *                 2010 by shk (Kuleshov Alexander kuleshovmail@gmail.com  *  
 * 																		   *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#ifndef MAINWIN_H
#define MAINWIN_H

#include <gtk/gtk.h>
#include <glib.h>
#include <glib-object.h>
#include <gtkimageview/gtkimageview.h>
#include <gtkimageview/gtkanimview.h>
#include <gtkimageview/gtkimagescrollwin.h>


#define MAIN_WIN_TYPE            (main_win_get_type ())
#define MAIN_WIN(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), MAIN_WIN_TYPE, MainWin))
#define MAIN_WIN_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), MAIN_WIN_TYPE, MainWinClass))
#define IS_MAIN_WIN(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), MAIN_WIN_TYPE))
#define IS_MAIN_WIN_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), MAIN_WIN_TYPE))
#define MAIN_WIN_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj), MAIN_WIN_TYPE, MainWinClass))

typedef enum
{
     ZOOM_NONE = 0,
     ZOOM_FIT,
     ZOOM_ORIG,
     ZOOM_SCALE
} ZoomMode;

typedef struct _MainWinClass
{
    GtkWindowClass parent_class;
} MainWinClass;

typedef struct _MainWin
{
    GtkWindow parent;
	GtkWidget* view;
	GtkWidget* scroll;
	GtkWidget* box;
	GtkAnimView* aview;
	GdkPixbuf* pix;
    GdkPixbufAnimation* animation;
	GtkWidget *toolbar;
    GtkUIManager *uimanager;
	GtkAccelGroup *accels;
} MainWin;

GtkWidget* main_win_new();

gboolean main_win_open( MainWin* mw, const char* file_path, ZoomMode zoom );

void main_win_show_error( MainWin* mw, const char* message );

GType main_win_get_type(void);

#endif 
