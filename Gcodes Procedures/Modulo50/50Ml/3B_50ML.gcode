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
G1 F600 E50 
G4 P200
G1 F600 E-50
G4 P200 

M117 Position 2
G1 F600 Y70 E50 
G4 P200
G1 F600 E-50 
G4 P200

M117 Position 3
G1 F600 Y70 E50 
G4 P200
G1 F600 E-50 
G4 P200

;end of first plate

;plate offset
G1 F240 Y4

;begin of second plate

M117 Position 4
G1 F600 Y70 E50 
G4 P200
G1 F600 E-50 
G4 P200

M117 Position 5
G1 F600 Y70 E50 
G4 P200
G1 F600 E-50 
G4 P200

M117 Position 6
G1 F600 Y70 E50 
G4 P200
G1 F600 E-50 
G4 P200

;end of second plate

;plate offset
G1 F240 Y4

;begin of third plate

M117 Position 7
G1 F600 Y70 E50 
G4 P200
G1 F600 E-50 
G4 P200

M117 Position 8
G1 F600 Y70 E50 
G4 P200
G1 F600 E-50 
G4 P200

M117 Position 9
G1 F600 Y70 E50 
G4 P200
G1 F600 E-50 
G4 P200

;end of third plate

;=================================================
G90  	; absolute Position
G1 F5000 Y10
G28 Y 	;home Y
G4 P1000


M117 procedure done.
