/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 0;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int systraypinning = 1;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayonleft = 1;   	/* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray        = 0;     /* 0 means no systray */
static const unsigned int gappih    = 15;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 15;       /* vert inner gap between windows */
static const unsigned int gappoh    = 10;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 15;       /* vert outer gap between windows and screen edge */
static       int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "UbuntuMono-R:size=12" };
static const char dmenufont[]       = "UbuntuMono-R:size=12";
static const char col_gray1[]       = "#282a36"; // statusbar background ||| Dark Gray
static const char col_gray2[]       = "#5a2788"; // inactive window border ||| Purple
static const char col_gray3[]       = "#e494ff"; // main text ||| Pink
static const char col_gray4[]       = "#dcd210"; // Active window Status text/selected tab text ||| Yellow
static const char col_cyan[]        = "#27282a"; // Active Window Status backgroung + Selected Tab backgroud + Active Window ||| Lighter Gray
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 }, // col_gray3, col_gray1, col_gray2
	[SchemeSel]  = { col_gray4, col_cyan,  col_gray3  }, // col_gray4, col_cyan,  col_cyan
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            0,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
	{ "Peek",     NULL,       NULL,       0,            1,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
        { "[@]",      spiral },
        { "[\\]",     dwindle },
        { "H[]",      deck },
        { "TTT",      bstack },
        { "===",      bstackhoriz },
        { "HHH",      grid },
        { "###",      nrowgrid },
        { "---",      horizgrid },
        { ":::",      gaplessgrid },
        { "|M|",      centeredmaster },
        { ">M>",      centeredfloatingmaster },
        { "><>",      NULL },    /* no layout function means floating behavior */
        { NULL,       NULL },
};

/* key definitions */
#include <X11/XF86keysym.h>
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
static const char *dmenucmd[] = { "rofi", "-show", "drun", NULL };
static const char *rofiswitchcmd[] = { "rofi", "-show", "window", NULL };
static const char *termcmd[]  = { "kitty", NULL };
static const char *printcmd[]  = { "flameshot", "gui", NULL };
static const char *printvcmd[]  = { "peek", NULL };
static const char *lockcmd[]  = { "slock", NULL };
static const char *quitcmd[]  = { "pkill", "dwm", NULL }; 
static const char *browsecmd[]  = { "firefox", NULL }; 
static const char *codecmd[]  = { "code", NULL }; 
static const char *filecmd[]  = { "pcmanfm", NULL }; 
static const char *volucmd[]  = { "volume.sh", "up", NULL }; 
static const char *voldcmd[]  = { "volume.sh", "down", NULL }; 
static const char *volmcmd[]  = { "volume.sh", "mute", NULL }; 
static const char *brightucmd[]  = { "brightnessctl", "s", "10%+", NULL }; 
static const char *brightdcmd[]  = { "brightnessctl", "s", "10%-", NULL }; 










static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_d,      spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_Tab,    spawn,          {.v = rofiswitchcmd } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_z,      spawn,          {.v = lockcmd } },
/*      { MODKEY|Mod4Mask,              XK_u,      incrgaps,       {.i = +1 } },
        { MODKEY|Mod4Mask|ShiftMask,    XK_u,      incrgaps,       {.i = -1 } },
        { MODKEY|Mod4Mask,              XK_i,      incrigaps,      {.i = +1 } },
        { MODKEY|Mod4Mask|ShiftMask,    XK_i,      incrigaps,      {.i = -1 } },
        { MODKEY|Mod4Mask,              XK_o,      incrogaps,      {.i = +1 } },
        { MODKEY|Mod4Mask|ShiftMask,    XK_o,      incrogaps,      {.i = -1 } },
        { MODKEY|Mod4Mask,              XK_6,      incrihgaps,     {.i = +1 } },
        { MODKEY|Mod4Mask|ShiftMask,    XK_6,      incrihgaps,     {.i = -1 } },
        { MODKEY|Mod4Mask,              XK_7,      incrivgaps,     {.i = +1 } },
        { MODKEY|Mod4Mask|ShiftMask,    XK_7,      incrivgaps,     {.i = -1 } },
        { MODKEY|Mod4Mask,              XK_8,      incrohgaps,     {.i = +1 } },
        { MODKEY|Mod4Mask|ShiftMask,    XK_8,      incrohgaps,     {.i = -1 } },
        { MODKEY|Mod4Mask,              XK_9,      incrovgaps,     {.i = +1 } },
        { MODKEY|Mod4Mask|ShiftMask,    XK_9,      incrovgaps,     {.i = -1 } },
*/ { MODKEY|Mod4Mask,              XK_0,      togglegaps,     {0} },
   { MODKEY|Mod4Mask|ShiftMask,    XK_0,      defaultgaps,    {0} },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_p,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY|ShiftMask,             XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_o,      setlayout,      {.v = &layouts[3]} },
	{ MODKEY,                       XK_u,      setlayout,      {.v = &layouts[12]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
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
	{ MODKEY|ShiftMask|ControlMask, XK_c,      spawn,           {.v = quitcmd } },
	{ MODKEY|ShiftMask,             XK_c,      quit,           {0} },
	{ NULL,                         XK_Print,  spawn,          {.v = printcmd } },
	{ MODKEY,                       XK_Print,  spawn,          {.v = printvcmd } },
	{ MODKEY|ShiftMask,             XK_b,      spawn,          {.v = browsecmd } },
	{ MODKEY|ShiftMask,             XK_t,      spawn,          {.v = codecmd } },
	{ MODKEY|ShiftMask,             XK_f,      spawn,          {.v = filecmd } },
	{ NULL,                         XF86XK_AudioRaiseVolume,  spawn,          {.v = volucmd } },
	{ NULL,                         XF86XK_AudioLowerVolume,  spawn,          {.v = voldcmd } },
	{ NULL,                         XF86XK_AudioMute,         spawn,          {.v = volmcmd } },
	{ NULL,                         XF86XK_MonBrightnessUp,   spawn,          {.v = brightucmd } },
	{ NULL,                         XF86XK_MonBrightnessDown, spawn,          {.v = brightdcmd } },
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

