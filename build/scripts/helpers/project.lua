#!lua

-- project.lua

local Table = require "scripts.helpers.table"
local PlatformSpecific = require "scripts.helpers.platform_specific"

local Project = { id = "Project"}
Project.__index = Project

function Project:new(obj)
    if(obj) then
        assert(type(obj) == "userdata" and obj.id == "Project", "Project:new expects a prototype of Project.")
    end

    local this = obj or {
        _name = "",
        _type = "",
        _dependencies = {},
        _extlibs = PlatformSpecific:new(),
        _linkOptions = PlatformSpecific:new(),
        _preprocessors = PlatformSpecific:new()
    }
    setmetatable(this, Project)
    self.__index = self

    return this
end

function Project:setName(name)
    assert(type(name) == "string", "Project:setName expects a string parameter.")
    self._name = name
end

function Project:getName()
    return self._name
end

function Project:setType(projectType)
    assert(type(projectType) == "string", "Project:setType expects a string parameter.")
    assert(projectType == "StaticLib" or projectType == "SharedLib" or projectType == "ConsoleApp" or projectType == "WindowedApp" or projectType == "Test", "A project type expects to be one of the following: 'ConsoleApp', 'WindowedApp', 'SharedLib', 'StaticLib', 'Test'.")
    self._type = projectType
end

function Project:getType()
    return self._type
end

function Project:addDependencies(dependencies)
    assert(type(dependencies) == "table", "Project:addDependencies expects a table parameter.")
    self._dependencies = Table.append(self._dependencies, dependencies)
end

function Project:getDependencies()
    return self._dependencies
end

function Project:addExtlibs(target, extlibs)
    assert(type(target) == "string", "Project:addExtlibs expects a string parameter as first parameter.")
    assert(target == "Windows" or target == "Unix" or target == "Common", "Extlibs can only be for 'Common', 'Windows', or 'Unix'.")
    assert(type(extlibs) == "table", "Project:addExtlibs expects a table parameter as second parameter.")
    if target == "Common" then
        self._extlibs:addToCommon(extlibs)
    elseif target == "Unix" then
        self._extlibs:addToUnix(extlibs)
    elseif target == "Windows" then
        self._extlibs:addToWindows(extlibs)
    end
end

function Project:getExtlibs()
    return self._extlibs:getAll()
end

function Project:addLinkOptions(target, linkOptions)
    assert(type(target) == "string", "Project:addLinkOptions expects a string parameter as first parameter.")
    assert(target == "Windows" or target == "Unix" or target == "Common", "linkOption can only be for 'Common', 'Windows', or 'Unix'.")
    assert(type(linkOptions) == "table", "Project:addLinkOptions expects a table parameter as second parameter.")
    if target == "Common" then
        self._linkOptions:addToCommon(linkOptions)
    elseif target == "Unix" then
        self._linkOptions:addToUnix(linkOptions)
    else
        self._linkOptions:addToWindows(linkOptions)
    end
end

function Project:getLinkOptions()
    return self._linkOptions:getAll()
end

function Project:addPreprocessors(target, preprocessors)
    assert(type(target) == "string", "Project:addPreprocessors expects a string parameter as first parameter.")
    assert(target == "Windows" or target == "Unix" or target == "Common", "linkOption can only be for 'Common', 'Windows', or 'Unix'.")
    assert(type(preprocessors) == "table", "Project:addPreprocessors expects a table parameter as second parameter.")
    if target == "Common" then
        self._preprocessors:addToCommon(preprocessors)
    elseif target == "Unix" then
        self._preprocessors:addToUnix(preprocessors)
    else
        self._preprocessors:addToWindows(preprocessors)
    end
end

function Project:getPreprocessors()
    return self._preprocessors:getAll()
end

return Project
