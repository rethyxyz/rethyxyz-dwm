/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int gappx     = 16;        /* gaps between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int usealtbar          = 0;        /* 1 means use non-dwm status bar */
static const char *altbarclass      = "polybar"; /* Alternate bar class name */
static const char *altbarcmd        = "$HOME/bar.sh"; /* Alternate bar launch command */
static const char *fonts[]          = { "BigBlue TerminalPlus:pixelsize=12" };
static const char dmenufont[]       = "BigBlue TerminalPlus:pixelsize=12";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_green[]       = "#00FF00";
static const char col_cyan[]        = "#8EB8AD";
static const char col_purple[]      = "#800080";
static const char col_black[]       = "#000000";
static const char col_red[]         = "#ff0000";
static const char col_yellow[]      = "#ffff00";
static const char col_white[]       = "#ffffff";
static const char *colors[][3]      = {
	/*               fg			  bg          border   */
	[SchemeNorm] =	 { col_gray3, col_gray1,  col_gray2 },
	[SchemeSel]  =	 { col_gray4, col_cyan,   col_cyan },
	[SchemeWarn] =	 { col_black, col_yellow, col_red },
	[SchemeUrgent]=	 { col_white, col_red,    col_red },
	[SchemeGreen]=	 { col_black, col_green,  col_green },
	[SchemePurple]=  { col_white, col_purple, col_purple },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
    { "mpv",      NULL,       NULL,       1 << 3,       1,           -1 },
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
	{ "qutebrowser", NULL,    NULL,       1 << 8,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */

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

static const char *bright_down[]  = { "light", "-U", "5", NULL };
static const char *bright_up[]  = { "light", "-A", "5", NULL };

static const char *browsercmd[]  = { "qutebrowser", NULL };
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *helpmenu[]  = { "zathura", "~/Documents/Repositories/dwm/README.pdf", NULL };

static const char *logout_request_handler[]  = { "logout_request_handler.sh", NULL };

static const char *mnt_drive[]  = { "st", "-e", "mnt_drive.sh", NULL };

static const char *mpc_next[]  = { "mpc", "-p", "6601", "next", NULL };
static const char *mpc_prev[]  = { "mpc", "-p", "6601", "prev", NULL };

static const char *mpc_seek_forward[]  = { "mpc", "-p", "6601", "seek", "+1%", NULL };
static const char *mpc_seek_backward[]  = { "mpc", "-p", "6601", "seek", "-1%", NULL };
static const char *mpc_toggle[]  = { "mpc", "-p", "6601", "toggle", NULL };

static const char *vol_up[]  = { "pactl", "set-sink-volume", "0", "+1%", NULL };
static const char *vol_down[]  = { "pactl", "set-sink-volume", "0", "-1%", NULL };
static const char *vol_mute[]  = { "pactl", "set-sink-mute", "0", "toggle", NULL };

static const char *picard[]  = { "picard", NULL };
static const char *ranger[]  = { "st", "-e", "ranger", NULL };
static const char *ncmpcpp[]  = { "st", "-e", "ncmpcpp", NULL };
static const char *neomutt[]  = { "st", "-e", "neomutt", NULL };
static const char *newsboat[]  = { "st", "-e", "newsboat", NULL };
static const char *restart_dwmbar[]  = { "restart_dwmbar.sh", NULL };
static const char *restart_request_handler[]  = { "restart_request_handler.sh", NULL };
static const char *scratchpad[]  = { "st", "-e", "vim", "~/Documents/Notes/Scratchpad", NULL };
static const char *slock[]  = { "slock", NULL };
static const char *soulseek[]  = { "soulseekqt", NULL };
static const char *termcmd[]  = { "st", NULL };
static const char *toggle_transparency[]  = { "toggle_transparency.sh", NULL };

/*
 * static const char *mnt_luks_drive[]  = { "st", "-e", "mnt_luks_drive.sh", NULL };
 * static const char *title_case[]  = { "st", "-e", "title_case.sh", NULL };
 * static const char *random_wallpaper[]  = { "randomize_wallpaper.sh", NULL };
*/

static Key keys[] = {
	/* modifier                     key        function			argument */

    /* Workspace */
	TAGKEYS(                        XK_1,						0)
	TAGKEYS(                        XK_2,						1)
	TAGKEYS(                        XK_3,						2)
	TAGKEYS(                        XK_4,						3)
	TAGKEYS(                        XK_5,						4)
	TAGKEYS(                        XK_6,						5)
	TAGKEYS(                        XK_7,						6)
	TAGKEYS(                        XK_8,						7)
	TAGKEYS(                        XK_9,						8)

    /* F1-12 */
	{ 0,							XK_F1,		togglefullscr,	{0} },
	{ 0,							XK_F4,		zoom,			{0} },
	{ 0,							XK_F6,		killclient,		{0} },
	{ 0,							XK_F9,		spawn,			{.v = helpmenu } },
	{ 0,							XK_F11,		focusstack,		{.i = -1 } },
	{ 0,							XK_F12,		focusstack,		{.i = +1 } },

    /* XF86 */
	{ 0, XF86XK_AudioMute,			spawn,						{.v = vol_mute } },
	{ 0, XF86XK_AudioLowerVolume,	spawn,						{.v = vol_down } },
	{ 0, XF86XK_AudioRaiseVolume,	spawn,						{.v = vol_up } },
	{ 0, XF86XK_MonBrightnessDown,	spawn,						{.v = bright_down } },
	{ 0, XF86XK_MonBrightnessUp,	spawn,						{.v = bright_up } },
	{ 0, XF86XK_AudioStop,			spawn,						{.v = ncmpcpp } },
	{ 0, XF86XK_AudioPrev,			spawn,						{.v = mpc_prev } },
	{ 0, XF86XK_AudioPlay,			spawn,						{.v = mpc_toggle } },
	{ 0, XF86XK_AudioNext,			spawn,						{.v = mpc_next } },

    /* Mod (using Mod4Mask) */
	{ MODKEY,						XK_F1,		spawn,			{.v = vol_mute } },
	{ MODKEY,						XK_F2,		spawn,			{.v = vol_down } },
	{ MODKEY,						XK_F3,		spawn,			{.v = vol_up } },
	{ MODKEY,						XK_F5,		spawn,			{.v = bright_down } },
	{ MODKEY,						XK_F6,		spawn,			{.v = bright_up } },
	{ MODKEY,						XK_F9,		spawn,			{.v = ncmpcpp } },
	{ MODKEY,						XK_F10,		spawn,			{.v = mpc_prev } },
	{ MODKEY,						XK_F11,		spawn,			{.v = mpc_toggle } },
	{ MODKEY,						XK_F12,		spawn,			{.v = mpc_next } },
	{ MODKEY,						XK_b,		spawn,			{.v = browsercmd } },
	{ MODKEY,						XK_d,		incnmaster,		{.i = -1 } },
	{ MODKEY,						XK_f,		setlayout,		{.v = &layouts[1]} },
	{ MODKEY,						XK_h,		focusmon,		{.i = -1 } },
	{ MODKEY,						XK_i,		incnmaster,     {.i = +1 } },
	{ MODKEY,						XK_j,		focusstack,		{.i = +1 } },
	{ MODKEY,						XK_k,		focusstack,		{.i = -1 } },
	{ MODKEY,						XK_l,		focusmon,		{.i = +1 } },
	{ MODKEY,						XK_n,		spawn,			{.v = ncmpcpp } },
	{ MODKEY,						XK_p,		spawn,          {.v = dmenucmd } },
	{ MODKEY,						XK_r,		spawn,			{.v = ranger } },
	{ MODKEY,						XK_s,		spawn,			{.v = soulseek } },
	{ MODKEY,						XK_t,	    setlayout,      {.v = &layouts[0]} },
 	{ MODKEY,                       XK_m,		setlayout,		{.v = &layouts[2]} },
	{ MODKEY,						XK_0,		view,			{.ui = ~0 } },
	{ MODKEY,						XK_Return,	spawn,			{.v = termcmd } },
	{ MODKEY,						XK_Tab,		view,			{0} },
	{ MODKEY,						XK_comma,	spawn,			{.v = mpc_seek_backward } },
	{ MODKEY,						XK_equal,	setgaps,		{.i = +1 } },
	{ MODKEY,						XK_minus,	setgaps,        {.i = -1 } },
	{ MODKEY,						XK_period,	spawn,			{.v = mpc_seek_forward } },
	{ MODKEY,						XK_space,   setlayout,      {0} },

    /* Mod+Alt */
	{ MODKEY|Mod1Mask,				XK_l,		spawn,			{.v = slock } },

    /* Mod+Shift */
	{ MODKEY|ShiftMask,				XK_b,		togglebar,		{0} },
	{ MODKEY|ShiftMask,				XK_c,		spawn,			{.v = logout_request_handler } },
	{ MODKEY|ShiftMask,				XK_f,		togglefullscr,	{0} },
	{ MODKEY|ShiftMask,				XK_h,		tagmon,			{.i = -1 } },
	{ MODKEY|ShiftMask,				XK_l,		tagmon,			{.i = +1 } },
	{ MODKEY|ShiftMask,				XK_m,		spawn,			{.v = neomutt } },
	{ MODKEY|ShiftMask,				XK_n,		spawn,			{.v = newsboat } },
	{ MODKEY|ShiftMask,				XK_p,		spawn,          {.v = picard } },
	{ MODKEY|ShiftMask,				XK_q,		killclient,		{0} },
	{ MODKEY|ShiftMask,				XK_r,		spawn,			{.v = restart_dwmbar } },
	{ MODKEY|ShiftMask,				XK_s,		spawn,			{.v = scratchpad } },
	{ MODKEY|ShiftMask,				XK_t,		spawn,			{.v = toggle_transparency } },
	{ MODKEY|ShiftMask,				XK_Return,	zoom,           {0} },
	{ MODKEY|ShiftMask,			    XK_BackSpace,	spawn,      {.v = restart_request_handler } },
	{ MODKEY|ShiftMask,				XK_equal,	setgaps,		{.i = 0  } },
 	{ MODKEY|ShiftMask,             XK_space,	togglefloating,	{0} },
	{ MODKEY|ShiftMask,				XK_0,		tag,			{.ui = ~0 } },

    /* Mod+Ctrl base binds*/
	{ MODKEY|ControlMask,			XK_h,		setmfact,		{.f = -0.01} },
	{ MODKEY|ControlMask,			XK_l,		setmfact,		{.f = +0.01} },
	{ MODKEY|ControlMask,			XK_m,		spawn,			{.v = mnt_drive } },
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

