
/* appearance */
static const unsigned int borderpx  = 3;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int gappih    = 6;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 6;       /* vert inner gap between windows */
static const unsigned int gappoh    = 6;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 6;       /* vert outer gap between windows and screen edge */
static const int smartgaps          = 1;        /* 1 means no outer gap when there is only one window */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "monospace:size=15" };
static const char dmenufont[]       = "monospace:size=15";
static const char col_gray1[]       = "#272536";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#555577";
//static const char col_border[]        = "#7f0000"; 	// dark red
static const char col_border[]        = "#3585C6"; 		// blue
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_border },
};

/* keybinding by nong10*/
#include <X11/XF86keysym.h>
static const char *suspend[] 		= { "/home/nong10/programs/scripts/suspend&lock", NULL};
static const char *brightness_up[] 	= { "/home/nong10/programs/scripts/brightnessup.sh", NULL};
static const char *brightness_down[]	= { "/home/nong10/programs/scripts/brightnessdown.sh", NULL};
	/* volume solution */
static const char *upvol[]   = { "/home/nong10/programs/scripts/volume", "-u", NULL};
static const char *downvol[] = { "/home/nong10/programs/scripts/volume", "-d", NULL};
static const char *mutevol[] = { "/home/nong10/programs/scripts/volume", "-m", NULL};
	/* screen lock key mapping */
static const char *screenlock[] = { "slock", NULL};
	/* screenshot mapping */
static const char *screenshot[] = { "flameshot", "full", "-p", "/home/nong10/Pictures/screenshots", NULL };

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *termcmd[]  = { "/home/nong10/programs/scripts/terminal.sh", NULL };
/* patch dwm-scratchpad */
static const char scratchpadname[] = "scratchpad";
static const char *scratchpadcmd[] = { "st", "-t", scratchpadname, "-g", "120x34", NULL };
/* dwm-scratchpad ends */

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_r,      spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
				/* rotate stack */
	{ MODKEY|ShiftMask,             XK_j,      rotatestack,    {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_k,      rotatestack,    {.i = -1 } },
				/* rotate stack ends */
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	/* vanitygaps */
	{ Mod1Mask|ShiftMask,           XK_h,      incrgaps,       {.i = +1 } },
	{ Mod1Mask|ShiftMask,           XK_l,      incrgaps,       {.i = -1 } },
//	{ MODKEY|Mod4Mask|ShiftMask,    XK_h,      incrogaps,      {.i = +1 } },
//	{ MODKEY|Mod4Mask|ShiftMask,    XK_l,      incrogaps,      {.i = -1 } },
//	{ MODKEY|Mod4Mask|ControlMask,  XK_h,      incrigaps,      {.i = +1 } },
//	{ MODKEY|Mod4Mask|ControlMask,  XK_l,      incrigaps,      {.i = -1 } },
//	{ MODKEY|Mod4Mask,              XK_0,      togglegaps,     {0} },
//	{ MODKEY|Mod4Mask|ShiftMask,    XK_0,      defaultgaps,    {0} },
//	{ MODKEY,                       XK_y,      incrihgaps,     {.i = +1 } },
//	{ MODKEY,                       XK_o,      incrihgaps,     {.i = -1 } },
//	{ MODKEY|ControlMask,           XK_y,      incrivgaps,     {.i = +1 } },
//	{ MODKEY|ControlMask,           XK_o,      incrivgaps,     {.i = -1 } },
//	{ MODKEY|Mod4Mask,              XK_y,      incrohgaps,     {.i = +1 } },
//	{ MODKEY|Mod4Mask,              XK_o,      incrohgaps,     {.i = -1 } },
//	{ MODKEY|ShiftMask,             XK_y,      incrovgaps,     {.i = +1 } },
//	{ MODKEY|ShiftMask,             XK_o,      incrovgaps,     {.i = -1 } },
	/* vanitygaps ends */
	{ MODKEY,                       XK_Return, zoom,           {0} },
	/* additional key for toggle master */
	{ Mod1Mask,                     XK_Tab,    zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_w,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY|ShiftMask,				XK_f,	   setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[2]} },
//	{ MODKEY,                     	XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	/* nextprevtag */
	{ MODKEY,              XK_i,           view_adjacent,  { .i = +1 } },
	{ MODKEY,              XK_u,           view_adjacent,  { .i = -1 } },
	/* nextprevtag ends */
	/* scratchpad */
	//{ MODKEY,                       XK_grave,  togglescratch,  {.v = scratchpadcmd } },
	/* scratchpad ends */
	/* using win shift t to quit dwm t for terminate */
	{ MODKEY|ShiftMask,             XK_t,      					quit,           {0} },
	{ 0,                       		XF86XK_AudioLowerVolume, 	spawn, {.v = downvol } },
	{ 0,                       		XF86XK_AudioMute, 			spawn, {.v = mutevol } },
	{ 0,                       		XF86XK_AudioRaiseVolume, 	spawn, {.v = upvol   } },
	{ 0,                            XF86XK_MonBrightnessUp,   	spawn, {.v = brightness_up } },
	{ 0,                            XF86XK_MonBrightnessDown, 	spawn, {.v = brightness_down } },
	/* suspend keybinding */
	{ MODKEY|ShiftMask,				XK_p,						spawn, {.v = suspend} },
	/* screenlock keybinding */
	{ MODKEY|ShiftMask, 			XK_l, 						spawn, {.v = screenlock }},
	/* screenshot keybinding */
	{ MODKEY|ShiftMask, 			XK_s, 						spawn, {.v = screenshot }}
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

