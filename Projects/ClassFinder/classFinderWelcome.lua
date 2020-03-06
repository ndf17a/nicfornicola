print("loaded: classFinderWelcome.lua")
--this is the "Class Finder" screen with the little hat on it, the first welcome screen
local composer = require("composer")
local scene = composer.newScene()
require("geoMapScene")
require("whereNow")
require("whereGoing")

local bg
local title
local titleText
local GoToBuildingList


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


	title = display.newImageRect("images/logo.png", 220, 170)
	title.alpha = 1


	local font = native.systemFont
	titleText = display.newText("", 0, 0, font, 23)
	titleText.aplha = 0


	GoToBuildingList = display.newText("Go to Building List", 0, 0, font, 25)
	GoToBuildingList.alpha = 0
    
    GoToGeomap = display.newText("See Full Acu Map", 0, 0, font, 20)
	GoToGeomap.alpha = 0
   

	titleGroup = display.newGroup()

	titleGroup:insert(title)
	titleGroup:insert(titleText)
	titleGroup:insert(GoToBuildingList)
    titleGroup:insert(GoToGeomap)


	titleText.y = title.height + 0.5 + 36


	GoToBuildingList.y = titleText.y + GoToBuildingList.height + -40
    GoToGeomap.y = titleText.y + GoToGeomap.height + 30


	titleGroup.x = _SCREEN.CENTER.x
	titleGroup.y = _SCREEN.CENTER.y - 48

	self.view:insert(bg)
	self.view:insert(titleGroup)


	transition.from(title,{
		time = 900,
		yScale = 0.1,
		xScale = 0.1,
		transition = easing.outBounce,
		onComplete = function()
        end
	})
	transition.to(title,{
		time = 900,
		aplha = 1,
		transition = easing.outQuad,
		onComplete = function()
		end
	})
	transition.to(titleText,{
		time = 900,
		delay = .5,
		alpha = 1,
		transition = easing.outQuad,
		onComplete = function()
			GoToBuildingList.alpha = 1
            GoToGeomap.alpha = 1
		end
	})
end


function scene:show(e)
	if(e.phase == "will") then
		function GoToBuildingList:tap(e)
			composer.gotoScene("whereNow", {effect = "slideLeft"})
		end
		GoToBuildingList:addEventListener("tap", GoToBuildingList)
	end

	if(e.phase == "will") then
		function GoToGeomap:tap(e)
			composer.gotoScene("geoMapScene", {effect = "slideRight"})
		end
		GoToGeomap:addEventListener("tap", GoToGeomap)
	end
end

scene:addEventListener("create", scene)
scene:addEventListener("show", scene)
scene:addEventListener("hide", scene)


return scene