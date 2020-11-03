info:
https://dwm.suckless.org/patches/nextprev/

examples:

static Key keys[] = {
	/* ... */
	{ MODKEY,              XK_i,           view_adjacent,  { .i = +1 } },
	{ MODKEY,              XK_u,           view_adjacent,  { .i = -1 } },
	/* ... */
};
static Button buttons[] = {
	/* ... */
	{ ClkTagBar,            0,              Button4,        view_adjacent,     { .i = -1 } },
	{ ClkTagBar,            0,              Button5,        view_adjacent,     { .i = +1 } },
	/* ... */
};
