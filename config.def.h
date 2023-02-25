/* appearance */
static const char font[]        = "Gohu GohuFont:size=11";
static const char* normbgcolor  = "#222222";
static const char* normfgcolor  = "#cccccc";
static const char* selbgcolor   = "#b2f66f";
static const char* selfgcolor   = "#222222";
static const char* urgbgcolor   = "#111111";
static const char* urgfgcolor   = "#cc0000";
static const char before[]      = "<";
static const char after[]       = ">";
static const char titletrim[]   = "...";
static const int  tabwidth      = 50;
static const Bool foreground    = True;
static       Bool urgentswitch  = False;

/*
 * Where to place a new tab when it is opened. When npisrelative is True,
 * then the current position is changed + newposition. If npisrelative
 * is False, then newposition is an absolute position.
 */
static int  newposition   = 0;
static Bool npisrelative  = False;

#define SETPROP(p) { \
        .v = (char *[]){ "/bin/sh", "-c", \
                "prop=\"$(xwininfo -children -id $1 | grep '^     0x' |" \
                "sed -e's@^ *\\(0x[0-9a-f]*\\) \"\\([^\"]*\\)\".*@\\1 \\2@' |" \
                "tail -n +2 | dmenu -i -l 10 -p 'Switch to: ')\" &&" \
                "xprop -id $1 -f $0 8s -set $0 \"$prop\"", \
                p, winid, NULL \
        } \
}

#define MOD Mod4Mask
#define SHIFT ShiftMask
#define CTRL ControlMask
#define ALT Mod1Mask
static Key keys[] = {
	/* modifier	key        function     argument */
	{ CTRL|SHIFT,   XK_Return, focusonce,   { 0 } },
	{ CTRL|SHIFT,   XK_Return, spawn,       { 0 } },
	{ CTRL|SHIFT,   XK_l,      rotate,      { .i = +1 } },
	{ CTRL|SHIFT,   XK_h,      rotate,      { .i = -1 } },
	{ CTRL|SHIFT,   XK_j,      movetab,     { .i = -1 } },
	{ CTRL|SHIFT,   XK_k,      movetab,     { .i = +1 } },
	{ CTRL,         XK_Tab,    rotate,      { .i = 0 } },
	{ CTRL,         XK_grave,  spawn,       SETPROP("_TABBED_SELECT_TAB") },
	{ CTRL,         XK_1,      move,        { .i = 0 } },
	{ CTRL,         XK_2,      move,        { .i = 1 } },
	{ CTRL,         XK_3,      move,        { .i = 2 } },
	{ CTRL,         XK_4,      move,        { .i = 3 } },
	{ CTRL,         XK_5,      move,        { .i = 4 } },
	{ CTRL,         XK_6,      move,        { .i = 5 } },
	{ CTRL,         XK_7,      move,        { .i = 6 } },
	{ CTRL,         XK_8,      move,        { .i = 7 } },
	{ CTRL,         XK_9,      move,        { .i = 8 } },
	{ CTRL,         XK_0,      move,        { .i = 9 } },

	{ CTRL,         XK_q,      killclient,  { 0 } },

	{ CTRL|SHIFT,   XK_u,      focusurgent, { 0 } },
	/* { CTRL,         XK_u,      toggle,      { .v = (void*) &urgentswitch } },*/
	{ 0,         XK_F11,       fullscreen, { 0 } },
};

