# mute_lock
AutoHotkey script written to use scroll lock to lock the pc.

With AHK script, when Scroll Lock is pressed the workstation will mute and lock.  This also toggles the scroll lock state off so the led (or whatever indicator) isn't active.

I also use this with a small program I wrote to unmute the system volume (if it's muted), which is run via Windows Task Scheduler with a workstation unlock trigger.
Since upgrading to Windows 10 the Task Scheduler Event trigger has worked without any hiccups, so no more need for multiple triggers (this will just run the task multiple times).  I am now only using the trigger of "On workstation unlock" for my account.

I've added two solutions to handle unmuting the system volume and set the volume to the provided level.

**MuteToggle.ahk** - Which can be converted to an exe with Ahk2exe, making it usable with Windows Task Scheduler.

**MuteToggle.cpp** - Can be compiled and used with Windows Task Manager.  This one requires the desired volume as an argument.

Both MuteToggle.ahk and MuteToggle.cpp will check the current mute state of the system.
If the system is not muted the program will mute the system.
If the system is muted the program will unmute and set the volume to a specified value.

Although I am only using these to unmute and set the volume, I figured adding a mute case to it would be good in the case of using it as a shortcut to easily toggle between the two states.
