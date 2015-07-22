# mute_lock
AutoHotkey script written use scroll lock to lock the pc.

With AHK script, when Scroll Lock is pressed the workstation will mute and lock.  This also toggles the scroll lock state off so the led (or whatever indicator) isn't active.

I also use this with a small program I wrote to unmute the system volume (if it's muted), which is run via Windows Task Scheduler with a workstation unlock trigger.  This has been unreliable, so I also included a trigger on event for event ID 4624.

Unmute program code not included, seems to be lost...
Will upload when found/rewritten
