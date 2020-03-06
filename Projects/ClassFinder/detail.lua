print("loaded: detail.lua")
local composer = require("composer")
local scene = composer.newScene()
local widget = require("widget")
local building = require("buildingData")


--includes whereNow and whereGoing so I can call the getIndex functions
require "whereGoing"
require "whereNow"


local filePath = whereGoing.getFullPath()

--prints the indices that were clicked from whereNow and whereGoing
print("FilePath:", filePath)

local navHeight = 44
local bg
local img
local titleText
local shadowText
local desciptionText
local blackbox
local whitebox
local menuBtn
local compass
local firstBuilding
local secondBuilding

function scene:create(e)
        
		local index = e.params.index
		local buildings = building[index]
		local brownGradientFill = {
		type = "gradient",
		color1 = {
			87/255,
			37/255,
			230/255,
			1
		},
		color2 = {
			38/255,
			16/255,
			0/255,
			1
		},
		direction = "down" --down left right up
	}
	bg = display.newRect(0, 0, _SCREEN.WIDTH, _SCREEN.HEIGHT)
	bg.x = _SCREEN.CENTER.x
	bg.y = _SCREEN.CENTER.y
	bg.fill = brownGradientFill

	img = display.newImageRect(filePath, 320, 400)
	img.anchorX = 0
	img.anchorY = 0
	img.y = navheight

    firstBuilding = whereNow.firstBuilding()
    secondBuilding = whereGoing.secondBuilding()
    --Name of Building
	titleText = display.newText(firstBuilding .. " -> " .. secondBuilding, 0, 0,native.systemFont, 15 )
	titleText.anchorX = 0
	titleText.anchorY = 1
	titleText.x = 12
	titleText.y = img.y + img.height +30
    --Name of Building Shadow
	shadowText = display.newText(buildings.name, 0, 0, native.systemFont, 15)
	shadowText.anchorX = 0
	shadowText.anchorY = 1
	shadowText.x = titleText.x + 1
	shadowText.y = titleText.y + 1
	shadowText.fill = {0,0,0,1}

    --Description
	descriptionText = display.newText({
		text = buildings.description,
		width = _SCREEN.WIDTH - 24,
		font = native.systemFont,
		fontSize = 20
		})
	descriptionText.anchorX = 0
	descriptionText.anchorY = 0
	descriptionText.x = 12
	descriptionText.y = img.y + img.height + 50

    
    compass = display.newImageRect("images/compass.png", 75, 80)
    compass.anchorX = 0
	compass.x = 240
	compass.y = navHeight 
    
    whitebox = display.newImageRect("images/whitebox.png", 55, 20)
    whitebox.anchorX = 0
	whitebox.x = 7
	whitebox.y = navHeight * .22
    
    blackbox = display.newImageRect("images/blackbox.png", 50, 18)
    blackbox.anchorX = 0
	blackbox.x = 10
	blackbox.y = navHeight * .22
    
    menuBtn = display.newText("< Back ", 0, 0, native.systemFont, 14)
	menuBtn.anchorX = 0
	menuBtn.x = 12
	menuBtn.y = navHeight * .22
    
    
    self.view:insert(bg)
	self.view:insert(img)
	self.view:insert(shadowText)
	self.view:insert(titleText)
	self.view:insert(descriptionText)
    self.view:insert(whitebox)
    self.view:insert(blackbox)
	self.view:insert(menuBtn)
    self.view:insert(compass)
end

function scene:show(e)
	if(e.phase == "will") then
		function menuBtn:tap(e)
			composer.gotoScene("whereGoing", {effect="slideRight"})
		end
		menuBtn:addEventListener("tap", menuBtn)
	end
    
	if(e.phase == "will") then
		function blackbox:tap(e)
			composer.gotoScene("whereGoing", {effect="slideRight"})
		end
		blackbox:addEventListener("tap", blackbox)
	end
end

function scene:hide(e)
	if(e.phase == "will") then
		composer.removeScene("detail")
	end
end

scene:addEventListener("create", scene)
scene:addEventListener("show", scene)
scene:addEventListener("hide", scene)

return scene