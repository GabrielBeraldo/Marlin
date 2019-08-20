
G21 	;set mm
G90 	;absolute coordinates
G28 Y 	;home Y

;first movimentation, to match the tips of nozzles to the drain structure

M400
M117 Drain position
G1 F1000 Y25

M400
M117 init. module
G28 I

M400
M117 1 - filling module
G1 F600 I20
G4 P200
M400
M117 1 - purging solut.
G1 F600 I0
G4 P200

M400
M117 2  - filling module
G1 F600 I20
G4 P200
M400
M117 2  - purging solut.
G1 F600 I0
G4 P200

M400
M117 1 - filling module
G1 F600 I20
G4 P200
M400
M117 1 - purging solut.
G1 F600 I0
G4 P200

M400
M117 2  - filling module
G1 F600 I20
G4 P200
M400
M117 2  - purging solut.
G1 F600 I0
G4 P200

M400
M117 procedure done.