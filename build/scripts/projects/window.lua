#!lua

-- window.lua

local Project = require "scripts.helpers.project"

local settings = Project:new()

settings:setName("window")
settings:setType("StaticLib")
settings:addDependencies{"core", "utility"}
settings:addExtlibs("Unix", {"xcb", "X11"})

return settings
