G21 	;set mm
G90 	;absolute coordinates
M117 home X
G28 X 

M400
M117 init. module
G28 I	;home E

G4 P500

;first movimentation in absulute Position 
;to reach first row of containers

;=================================================

; begin of the fist plate
;========================
;first offset
G1 F3000 X66
G91 	;relative coordinates
;========================

M400
M117 Position 1
G1 F180 I20 
G4 P200
G1 F180 I-20
G4 P200 

M400
M117 Position 2
G1 F216 X24 I20 
G4 P200
G1 F180 I-20 
G4 P200

M400
M117 Position 3
G1 F216 X24 I20 
G4 P200
G1 F180 I-20 
G4 P200

M400
M117 Position 4
G1 F216 X24 I20 
G4 P200
G1 F180 I-20 
G4 P200

M400
M117 Position 5
G1 F216 X24 I20 
G4 P200
G1 F180 I-20 
G4 P200

M400
M117 Position 6
G1 F216 X24 I20 
G4 P200
G1 F180 I-20 
G4 P200

M400
M117 Position 7
G1 F216 X24 I20 
G4 P200
G1 F180 I-20 
G4 P200

M400
M117 Position 8
G1 F216 X24 I20 
G4 P200
G1 F180 I-20 
G4 P200

M400
M117 Position 9
G1 F216 X24 I20 
G4 P200
G1 F180 I-20 
G4 P200

M400
M117 Position 10
G1 F216 X24 I20 
G4 P200
G1 F180 I-20 
G4 P200

M400
M117 Position 11
G1 F216 X24 I20 
G4 P200
G1 F180 I-20 
G4 P200

M400
M117 Position 12
G1 F216 X24 I20 
G4 P200
G1 F180 I-20 
G4 P200

M400
M117 Position 13
G1 F216 X24 I20 
G4 P200
G1 F180 I-20 
G4 P200

M400
M117 Position 14
G1 F216 X24 I20 
G4 P200
G1 F180 I-20 
G4 P200

M400
M117 Position 15
G1 F216 X24 I20 
G4 P200
G1 F180 I-20 
G4 P200

M400
M117 Position 16
G1 F216 X24 I20 
G4 P200
G1 F180 I-20 
G4 P200

M400
M117 Position 17
G1 F216 X24 I20 
G4 P200
G1 F180 I-20 
G4 P200

M400
M117 Position 18
G1 F216 X24 I20 
G4 P200
G1 F180 I-20 
G4 P200

M400
M117 Position 19
G1 F216 X24 I20 
G4 P200
G1 F180 I-20 
G4 P200

M400
M117 Position 20
G1 F216 X24 I20 
G4 P200
G1 F180 I-20 
G4 P200


;end of first plate


;=================================================
G90  	; absolute Position
G1 F6000 X10
G4 P1000


M117 procedure done.
