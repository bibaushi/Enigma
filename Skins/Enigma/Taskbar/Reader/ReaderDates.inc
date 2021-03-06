[Variables]
WebParserSubstitute="<![CDATA[":"","]]>":"","/PRE&gt;":"","PRE&gt;":"","&nbsp;":" ","'s Facebook Notifications":"","Top Stories - Google ":""

;---------------------------------------------------------------------
; MEASURES

[MeasureFeed]
Measure=WebParser
UpdateRate=600
Url=#ReaderURL#
RegExp=(?siU)(.*)$
DecodeCharacterReference=1
Substitute=#WebParserSubstitute#
FinishAction=!CommandMeasure MeasureScriptReader Refresh()

[MeasureScriptReader]
Measure=Script
ScriptFile="#@#Measures\Reader.lua"
MeasureName=MeasureFeed
WriteEvents=#ReaderWriteEvents#
EventFile=#ReaderEventFile#
FinishAction=[!UpdateMeasureGroup "FeedData"][!UpdateMeterGroup "FeedData"][!Redraw]

;---------------------------------------------------------------------
; METERS

[Background]
Meter=Image
MeterStyle=Style#Variant#Background

[Icon]
Meter=IMAGE
Group=FeedData
MeterStyle=Style#Variant#Icon | #ReaderIconStyle#
LeftMouseUpAction=["#Item1Link#"]
DynamicVariables=1

[Text]
Meter=STRING
Group=FeedData
MeterStyle=Style#Variant#Text
Text=#Item1Title#
LeftMouseUpAction=["#Item1Link#"]
DynamicVariables=1

[Label]
Meter=STRING
Group=FeedData
MeterStyle=Style#Variant#Label
Text=#Item1Date#
DynamicVariables=1