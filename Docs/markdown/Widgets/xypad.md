# XY Pad

xypad is an x/y controller that sends data to Csound on two named channels. The first channel transmits the current position of the ball on the X axis, while the second transmits the position of the ball on the Y axis. The XY pad can function in two unique modes of automation, free and path based. The two modes can be toggled by clicking on the corresponding icon on the bottom left of the xypad control. With either mode selected you can right-click the xypad and create a trajectory or path for the circle's movement. Release the mouse and the circle will start moving. Once the ball is in full flight you can control the speed of the ball using the XY pad slider that will appear once you hover over it with the mouse. To stop the ball simple left click anywhere on the xy pad canvas with the left mouse button. 

<big></pre>
xypad WIDGET_SYNTAX
</pre></big>

### Specific Identifiers

{! ./markdown/Widgets/Properties/channel_xypad.md !} 

{! ./markdown/Widgets/Properties/text_xypad.md !} 

**rangex(min, max, value)** sets the range of the X axis. The first 2 parameters are required. The third is optional. The first two parameters let you set the minimum value and the maximum value. The next parameter determines the initial value. 

**rangey(min, max, value)** sets the range of the Y axis. The first 2 parameters are required. The third is optional. The first two parameters let you set the minimum value and the maximum value. The next parameter determines the initial value. 

{! ./markdown/Widgets/Properties/textcolour.md !} 

### Common Identifiers

{! ./markdown/Widgets/Properties/bounds.md !} 

{! ./markdown/Widgets/Properties/value.md !}  

{! ./markdown/Widgets/Properties/identchannel.md !}  

{! ./markdown/Widgets/Properties/visible.md !}   

{! ./markdown/Widgets/Properties/active.md !}   

{! ./markdown/Widgets/Properties/colour.md !}   

{! ./markdown/Widgets/Properties/fontcolour.md !}  

{! ./markdown/Widgets/Properties/alpha.md !}   

{! ./markdown/Widgets/Properties/tofront.md !} 

{! ./markdown/Widgets/Properties/widgetarray.md !}  

> XY pads range identifiers do not permit the setting of skew factors, or increments. If you wish to set a custom skew factor, or increment value, you will need to do so using Csound code.  


<!--(End of identifiers)/-->

![](../images/xypad.gif)


##Example:
<!--(Widget Example)/-->
```csharp
<Cabbage>
form caption("XY-Pad Example") size(400, 300), colour(220, 220, 220), pluginID("def1")
xypad bounds(10, 10, 380, 280), channel("xChannel", "yChannel"), rangex(0, 1000, 100), rangey(0, 1000, 100), textcolour("yellow"), text("XY-PAD")
</Cabbage>
<CsoundSynthesizer>
<CsOptions>
-n -d -+rtmidi=NULL -M0 -m0d 
</CsOptions>
<CsInstruments>
; Initialize the global variables. 
sr = 44100
ksmps = 32
nchnls = 2
0dbfs = 1

seed 0 
;basic usage
instr 1
kXVal chnget "xChannel"
kYVal chnget "yChannel"
a1 oscili 1, kXVal
a2 oscili a1, kYVal
outs a2, a2
endin

</CsInstruments>
<CsScore>
;causes Csound to run for about 7000 years...
f0 z
;starts instrument 1 and runs it for a week
i1 0 z
</CsScore>
</CsoundSynthesizer> 
```
<!--(End Widget Example)/-->