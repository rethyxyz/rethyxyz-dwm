# rethyxyz-dwm
My build of dwm. Minimally patched. Contains altbar, transparency, fullscreen, statuscolors, and gaps patches. Supports XF86 keys.

<center> <img title="rethyxyz-dwm preview" src="./rethyxyz-dwm_preview.png" width=720px> </center>

## Keybindings
Window manipulation:
- **F1**/**Super + Shift + f**: Toggle fullscreen
- **F6**/**Super + Shift + q**: Kill selected frame/window
- **F4**/**Super + Shift + Return**: Select window as master/Last frame/window as primary
- **Super + Ctrl + h**: Resize tag -1
- **Super + Ctrl + l**: Resize tag +1
- **Super + Equal**: Increment gaps +1
- **Super + Minus**: Increment gaps -1
- **Super + Shift + equal**: Set gaps to 0
- **Super + Shift + b**: Toggle status bar
- **Super + Shift + c**: Kill dwm (logout)
- **Super + Shift + h**: Move selected window to monitor -1
- **Super + Shift + l**: Move selected window to monitor +1
- **Super + d**: Increment master -1
- **Super + i**: Increment master +1
- **Super + j**: Focus stack +1
- **Super + k**: Focus stack -1
- **Super + l**: Goto monitor +1 (left)
- **Super + h**: Goto monitor -1 (left)

Layouts:
- **Super + f**: Set layout floating
- **Super + m**: Set layout monocle
- **Super + t**: Set layout tiling
- **Super + space**: Toggle float/tiling layout

Workspace/tag manipulation:
- **Super + 1-9**: Go to workspace/tag 1 - 9
- **Super + Shift + 1-9**: Move primary frame/window to workspace/tag 1 - 9
- **Super + 0**: View all tags
- **Super + XK_Tab**: Goto previous workspace/tag

Volume:
- **Super + F1**/**XF86_AudioMute**: Volume mute
- **Super + F2**/**XF86_AudioLowerDown**: Volume down
- **Super + F3**/**XF86_AudioRaiseUp**: Volume up

Brightness:
- **Super + F5**/**XF86_MonBrightnessDown**: Brightness down
- **Super + F6**/**XF86_MonBrightnessUp**: Brightness up

Music:
- **Super + F10**/**XF86_AudioPrev**: Mpc previous song
- **Super + F11**/**XF86_AudioPlay**: Mpc toggle pause/play song
- **Super + F12**/**XF86_AudioNext**: Mpc next song
- **Super + comma**: Mpc seek backward
- **Super + period**: Mpc seek forward

Execute programs:
- **Super + Return** Spawn simple terminal (st)
- **Super + Ctrl + m**: spawn Mount USB script
- **Super + Ctrl + t**: spawn Title case script
- **Super + Shift + m**: Spawn mutt
- **Super + Shift + n**: Spawn newsboat
- **Super + Shift + p**: Spawn picard
- **Super + Shift + r**: Spawn random_wallpaper script
- **Super + Shift + s**: Spawn scratchpad
- **Super + Shift + t**: Spawn TODO file in vim
- **Super + b**: Spawn qutebrowser
- **Super + p**: Spawn dmenu
- **Super + r**: Spawn ranger
- **Super + s**: Spawn soulseek
- **Super + F9**/**XF86_AudioStop**/**Super + n**: Spawn Ncmpcpp (NCurses Music Player Plus Plus)

See `config.h` for other keybindings not included here.
