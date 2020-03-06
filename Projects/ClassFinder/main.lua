_SCREEN = { 
	HEIGHT = display.contentHeight,
	WIDTH = display.contentWidth
}

_SCREEN.CENTER = {
	x = display.contentCenterX,
	y = display.contentCenterY
}

display.setStatusBar(display.HiddenStatusBar)

print("\n\n/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\REBUILD/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\\n")
local composer = require("composer")
composer.gotoScene("classFinderWelcome")
