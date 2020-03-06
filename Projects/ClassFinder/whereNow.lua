print("loaded: whereNow.lua")
local composer = require ("composer")
local scene = composer.newScene()
local widget = require("widget")
local building = require("buildingData")

local navHeight = 44
local bg
local tableView
local menuBtn
local topTag

local function onRowRender(e)
	local row = e.row
	local rowIndex = row.index
	local rowLabel
	local rowThumbnail

	rowLabel = e.row.params.title
	rowThumbnail = e.row.params.thumbnail

	row.rowThumbnail = display.newImageRect(rowThumbnail, 60, 60)
	row.rowThumbnail.anchorX = 0
	row.rowThumbnail.x = 12
	row.rowThumbnail.y = row.height * 0.5

	row.rowText = display.newText(rowLabel, 0, 0, display.systemFont, 12)
	row.rowText.anchorX = 0
	row.rowText.x = row.rowThumbnail.width + row.rowThumbnail.x + 12
	row.rowText.y = row.height * 0.5
	row.rowText.fill = {0,0,0,1}

	row:insert(row.rowThumbnail)
	row:insert(row.rowText)
end

--Need this for the getNowIndex function
module("whereNow", package.seeall)

local function onRowTouch(e)
    local index = e.target.params.index
    local buildings = building[index]
      --returns index of the buildings tapped
      function getNowIndex()
            local path = "images/" .. buildings.name
            return path
      end
    
      function firstBuilding()
            return buildings.name
      end
    
	if(e.phase == "tap") then
		if(e.target.params) then
			composer.gotoScene("whereGoing",{
				effect = "slideLeft",
				params = {
					index = e.target.params.index
                        }
				 
			})
		end
	end
end


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

    topTag = display.newText("Where are You Now", 0, 0, native.systemFont, 18)
    topTag.anchorX = 0
	topTag.x = 150
	topTag.y = navHeight * 0.5
    
	menuBtn = display.newText("< Home ", 0, 0, native.systemFont, 14)
	menuBtn.anchorX = 0
	menuBtn.x = 12
	menuBtn.y = navHeight * .20



	local tableView = widget.newTableView({
		left = 0,
		top = navHeight,
		height = _SCREEN.HEIGHT - navHeight,
		width = _SCREEN.HEIGHT,

		onRowRender = onRowRender,
		onRowTouch = onRowTouch

		--onRowTouch = onRowTouch
	})

	self.view:insert(bg)
	self.view:insert(tableView)
    self.view:insert(topTag)
	self.view:insert(menuBtn)
    

	for i = 1, #building do
		local buildings = building[i].name
		local thumbnail = building[i].thumbnail
            local params = {
			isCategory = false,
			rowHeight = 60,
			rowColor = {
				default = {1,1,1,1},
				over = {1,1,1,1}
			},
			params = {
				title = buildings,
				thumbnail = thumbnail,
				index = i
			}	
		}

		tableView:insertRow(params)
	end
end

function scene:show(e)
	if(e.phase == "will") then
		function menuBtn:tap(e)
			composer.gotoScene("classFinderWelcome", {effect="slideRight"})
		end
		menuBtn:addEventListener("tap", menuBtn)
	end
end


scene:addEventListener("create", scene)
scene:addEventListener("show", scene)
scene:addEventListener("hide", scene)

return scene