
G21 	;set mm
G90 	;absolute coordinates
G28 Y 	;home Y

;first movimentation, to match the tips of nozzles to the drain structure
M117 Drain position
G1 F3000 Y10

M117 init. module
G28 E

M117 1 - filling module
G1 F180 E20
G4 P200
M117 1 - purging solut.
G1 F180 E0
G4 P200

M117 2  - filling module
G1 F180 E20
G4 P200
M117 2  - purging solut.
G1 F180 E0
G4 P200

M117 3  - filling module
G1 F180 E20
G4 P200
M117 3  - purging solut.
G1 F180 E0
G4 P200

M117 procedure done.