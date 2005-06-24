/*
 * Copyright (C) 2005 National Association of REALTORS(R)
 *
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, and/or sell copies of the
 * Software, and to permit persons to whom the Software is furnished
 * to do so, provided that the above copyright notice(s) and this
 * permission notice appear in all copies of the Software and that
 * both the above copyright notice(s) and this permission notice
 * appear in supporting documentation.
 */
#include <iostream>
#include <boost/lexical_cast.hpp>
#include "librets/MetadataElement.h"
#include "librets/util.h"

using namespace librets;
using namespace librets::util;
using std::string;
using std::vector;
using boost::lexical_cast;

#define CLASS MetadataElement

CLASS::CLASS()
{
}

CLASS::~CLASS()
{
}

CLASS::MetadataType MetadataElement::GetType() const
{
    return SYSTEM;
}

string CLASS::GetStringAttribute(string attributeName,
                                 string defaultValue) const
{
    StringMap::const_iterator i = mAttributes.find(attributeName);
    if (i != mAttributes.end())
    {
        return i->second;
    }
    else
    {
        return defaultValue;
    }
}

int CLASS::GetIntAttribute(string attributeName, int defaultValue) const
{
    StringMap::const_iterator i = mAttributes.find(attributeName);
    if (i != mAttributes.end())
    {
        return lexical_cast<int>(i->second);
    }
    else
    {
        return defaultValue;
    }
}

bool CLASS::GetBoolAttribute(string attributeName, bool defaultValue) const
{
    StringMap::const_iterator i = mAttributes.find(attributeName);
    if (i != mAttributes.end())
    {
        return lexical_cast<bool>(i->second);
    }
    else
    {
        return defaultValue;
    }
}

void CLASS::SetAttribute(string attributeName, string attributeValue)
{
    mAttributes[attributeName] = attributeValue;
}

vector<MetadataElementPtr> MetadataElement::GetChildren(MetadataType type)
{
    vector<MetadataElementPtr> children;
    return children;
}

string CLASS::GetLevel() const
{
    return mLevel;
}

void CLASS::SetLevel(string level)
{
    mLevel = level;
}

std::ostream & CLASS::Print(std::ostream & outputStream) const
{
    return outputStream << "Type [" << GetType() << "], level [" << mLevel
                        << "]";
}
