G21 	;set mm
G90 	;absolute coordinates
G28 Y 	;home Y

;first movimentation in absulute Position 
;to reach first row of containers

;=================================================

; begin of the fist plate
;========================
;first offset
G1 F3000 Y65
G91 	;relative coordinates
;========================

M117 Position 1
G1 F180 E20 
G4 P200
G1 F180 E-20
G4 P200 

;=================================================
G90  	; absolute Position
G1 F6000 Y25
G4 P1000


M117 Procedure done.