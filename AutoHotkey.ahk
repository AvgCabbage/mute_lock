ScrollLock::
SetScrollLockState, Off
DllCall("LockWorkStation")
Send {Volume_Mute}
Return
