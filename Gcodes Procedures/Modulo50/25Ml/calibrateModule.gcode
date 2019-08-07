G21 	;set mm
G90 	;absolute coordinates
G28 Y 	;home Y

;first movimentation in absulute Position 
;to reach first row of containers

;=================================================

; begin of the fist plate
;========================
;first offset
G1 F1000 Y25
G91 	;relative coordinates
;========================

M117 Position 1
G1 F600 E25 
G4 P200
G1 F600 E-25
G4 P200 

;=================================================
G90  	; absolute Position
G1 F5000 Y10
G28 Y 	;home Y
G4 P1000


M117 Procedure done.