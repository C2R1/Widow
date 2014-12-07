--Create a table wich contains all motors
botBodyParts = { 'Ant_joint1Leg1', 'Ant_joint2Leg1', 'Ant_joint3Leg1',
                 'Ant_joint1Leg2', 'Ant_joint2Leg2', 'Ant_joint3Leg2',
                 'Ant_joint1Leg3', 'Ant_joint2Leg3', 'Ant_joint3Leg3',
                 'Ant_joint1Leg4', 'Ant_joint2Leg4', 'Ant_joint3Leg4',
                 'Ant_joint1Leg5', 'Ant_joint2Leg5', 'Ant_joint3Leg5',
                 'Ant_joint1Leg6', 'Ant_joint2Leg6', 'Ant_joint3Leg6',
                 'Ant_neckJoint1', 'Ant_neckJoint2', 'Ant_neckJoint3'}
--
function file_exists(name)
   local f=io.open(name,"r")
   if f~=nil then io.close(f) return true else return false end
end
j = 0
while j < 1000 do
	--Set all motors positions
    if not file_exists($$INPUT$$ .. j) then
      break
    end
	i = 0
	for line in io.lines($$INPUT$$ .. j ) do 
	  i = i + 1
	  simSetJointPosition(simGetObjectHandle(botBodyParts[i]),tonumber(line)*math.pi/180)
	end
	--Write the result position
	local endFile = io.open($$OUTPUT$$ .. j, "w")
	pos = simGetObjectPosition(simGetObjectHandle('Ant_base'), -1)
	endFile:write(pos[1])
	endFile:write('\n')
	endFile:write(pos[2])
	endFile:write('\n')
	endFile:write(pos[3])
	endFile:close()
    j = j + 1
end
--Stop the simulation
simStopSimulation()
