
G21 	;set mm
G90 	;absolute coordinates
G28 Y 	;home Y

;first movimentation, to match the tips of nozzles to the drain structure

M400
M117 Drain position
G1 F3000 Y25

M400
M117 Init. module
G28 I

M400
M117 1 - Filling module
G1 F600 I50
G4 P200
M400
M117 1 - Purging solut.
G1 F600 I0
G4 P200

M400
M117 2  - Filling module
G1 F600 I50
G4 P200
M400
M117 2  - Purging solut.
G1 F600 I0
G4 P200

M400
M117 3  - Filling module
G1 F600 I50
G4 P200
M400
M117 3  - Purging solut.
G1 F600 I0
G4 P200


M400
M117 Procedure done.