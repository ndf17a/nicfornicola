print("loaded: geoMapScene.lua")
--this is the "GeoMap" 
local composer = require("composer")
local scene = composer.newScene()

local bg
local menuBtn
local blackbox
local map

function scene:create(e)
	local brownGradientFill = {
		type = "gradient",
		color1 = {
			200/255,
			0/255,
			230/255,
			1
		},
		color2 = {
			38/255,
			16/255,
			0/255,
			1
		},
		direction = "down" --this can me down left right up
	}
	bg = display.newRect(0, 0, _SCREEN.WIDTH, _SCREEN.HEIGHT)
	bg.x = _SCREEN.CENTER.x
	bg.y = _SCREEN.CENTER.y
	bg.fill = brownGradientFill

    map = display.newImageRect("images/acuMap.png", _SCREEN.WIDTH, _SCREEN.HEIGHT)
    map.x = _SCREEN.CENTER.x
    map.y = _SCREEN.CENTER.y
    
    
    blackbox = display.newImageRect("images/blackbox.png", 55, 18)
    blackbox.anchorX = 0
	blackbox.x = _SCREEN.WIDTH - 62
    blackbox.y = 10
	
    menuBtn = display.newText("Home >", 0, 0, native.systemFont, 14)
	menuBtn.anchorX = 0
	menuBtn.x = _SCREEN.WIDTH - 60
	menuBtn.y = 10
    
    self.view:insert(bg)
    self.view:insert(map)
    self.view:insert(blackbox)
	self.view:insert(menuBtn)
    
end

function scene:show(e)
	if(e.phase == "will") then
		function menuBtn:tap(e)
			composer.gotoScene("classFinderWelcome", {effect="slideLeft"})
		end
		menuBtn:addEventListener("tap", menuBtn)
	end
    
	if(e.phase == "will") then
		function blackbox:tap(e)
			composer.gotoScene("classFinderWelcome", {effect="slideLeft"})
		end
		blackbox:addEventListener("tap", blackbox)
	end
end
scene:addEventListener("create", scene)
scene:addEventListener("show", scene)
scene:addEventListener("hide", scene)


return scene