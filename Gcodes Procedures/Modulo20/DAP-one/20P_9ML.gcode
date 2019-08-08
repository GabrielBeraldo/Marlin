G21 	;set mm
G90 	;absolute coordinates
M117 home em Y
G28 Y 
G1 F3000 Y10
M117 init. module
G28 E	;home E
G4 P500

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
G1 F180 E9 
G4 P200
G1 F180 E-9
G4 P200 

M117 Position 2
G1 F440 Y22 E9 
G4 P200
G1 F180 E-9 
G4 P200

M117 Position 3
G1 F440 Y22 E9 
G4 P200E-9
G1 F180 E-9 
G4 P200

117 Position 4
G1 F440 Y22 E9 
G4 P200
G1 F180 E-9 
G4 P200

M117 Position 5
G1 F440 Y22 E9 
G4 P200E-9
G1 F180 E-9 
G4 P200

117 Position 6
G1 F440 Y22 E9 
G4 P200
G1 F180 E-9 
G4 P200

M117 Position 7
G1 F440 Y22 E9 
G4 P200E-9
G1 F180 E-9 
G4 P200

117 Position 8
G1 F440 Y22 E9 
G4 P200
G1 F180 E-9 
G4 P200

M117 Position 9
G1 F440 Y22 E9 
G4 P200E-9
G1 F180 E-9 
G4 P200

117 Position 10
G1 F440 Y22 E9 
G4 P200
G1 F180 E-9 
G4 P200

M117 Position 11
G1 F440 Y22 E9 
G4 P200E-9
G1 F180 E-9 
G4 P200

117 Position 12
G1 F440 Y22 E9 
G4 P200
G1 F180 E-9 
G4 P200

M117 Position 13
G1 F440 Y22 E9 
G4 P200E-9
G1 F180 E-9 
G4 P200

117 Position 14
G1 F440 Y22 E9 
G4 P200
G1 F180 E-9 
G4 P200

M117 Position 15
G1 F440 Y22 E9 
G4 P200E-9
G1 F180 E-9 
G4 P200

117 Position 16
G1 F440 Y22 E9 
G4 P200
G1 F180 E-9 
G4 P200

M117 Position 17
G1 F440 Y22 E9 
G4 P200E-9
G1 F180 E-9 
G4 P200

117 Position 18
G1 F440 Y22 E9 
G4 P200
G1 F180 E-9 
G4 P200

M117 Position 19
G1 F440 Y22 E9 
G4 P200E-9
G1 F180 E-9 
G4 P200

117 Position 20
G1 F440 Y22 E9 
G4 P200
G1 F180 E-9 
G4 P200


;end of first plate


;=================================================
G90  	; absolute Position
G1 F6000 Y10
G4 P1000


M117 procedure done.
