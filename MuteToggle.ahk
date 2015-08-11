
NewVolume := 4
SoundGet, MuteState, ,Mute

;MsgBox, Master Mute is currently %MuteState%

if( MuteState = "Off" )
{
	;MsgBox, Muted
	SoundSet, 1, Master, Mute
}
else if( MuteState = "On" )
{
	;MsgBox, UnMuted
	SoundSet, 0, Master, Mute
	SoundSet, NewVolume
}