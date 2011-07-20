/* --------------------------------------------------------------------------

   libmusicbrainz4 - Client library to access MusicBrainz

   Copyright (C) 2011 Andrew Hawkins

   This file is part of libmusicbrainz4.

   This library is free software; you can redistribute it and/or
   modify it under the terms of v2 of the GNU Lesser General Public
   License as published by the Free Software Foundation.

   Flactag is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with this library; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

     $Id$

----------------------------------------------------------------------------*/

#include "musicbrainz4/NonMBTrack.h"

class MusicBrainz4::CNonMBTrackPrivate
{
	public:
		CNonMBTrackPrivate()
		:	m_Length(0)
		{
		}

		std::string m_Title;
		std::string m_Artist;
		int m_Length;
};

MusicBrainz4::CNonMBTrack::CNonMBTrack(const XMLNode& Node)
:	CEntity(),
	m_d(new CNonMBTrackPrivate)
{
	if (!Node.isEmpty())
	{
		//std::cout << "NonMBTrack node: " << std::endl << Node.createXMLString(true) << std::endl;

		Parse(Node);
	}
}

MusicBrainz4::CNonMBTrack::CNonMBTrack(const CNonMBTrack& Other)
:	CEntity(),
	m_d(new CNonMBTrackPrivate)
{
	*this=Other;
}

MusicBrainz4::CNonMBTrack& MusicBrainz4::CNonMBTrack::operator =(const CNonMBTrack& Other)
{
	if (this!=&Other)
	{
		CEntity::operator =(Other);

		m_d->m_Title=Other.m_d->m_Title;
		m_d->m_Artist=Other.m_d->m_Artist;
		m_d->m_Length=Other.m_d->m_Length;
	}

	return *this;
}

MusicBrainz4::CNonMBTrack::~CNonMBTrack()
{
	delete m_d;
}

bool MusicBrainz4::CNonMBTrack::ParseAttribute(const std::string& Name, const std::string& /*Value*/)
{
	bool RetVal=true;

	std::cerr << "Unrecognised non MB track attribute: '" << Name << "'" << std::endl;
	RetVal=false;

	return RetVal;
}

bool MusicBrainz4::CNonMBTrack::ParseElement(const XMLNode& Node)
{
	bool RetVal=true;

	std::string NodeName=Node.getName();

	if ("title"==NodeName)
	{
		RetVal=ProcessItem(Node,m_d->m_Title);
	}
	else if ("artist"==NodeName)
	{
		RetVal=ProcessItem(Node,m_d->m_Artist);
	}
	else if ("length"==NodeName)
	{
		RetVal=ProcessItem(Node,m_d->m_Length);
	}
	else
	{
		std::cerr << "Unrecognised non MB track element: '" << NodeName << "'" << std::endl;
		RetVal=false;
	}

	return RetVal;
}

std::string MusicBrainz4::CNonMBTrack::Title() const
{
	return m_d->m_Title;
}

std::string MusicBrainz4::CNonMBTrack::Artist() const
{
	return m_d->m_Artist;
}

int MusicBrainz4::CNonMBTrack::Length() const
{
	return m_d->m_Length;
}

std::ostream& operator << (std::ostream& os, const MusicBrainz4::CNonMBTrack& NonMBTrack)
{
	os << "NonMBTrack:" << std::endl;

	MusicBrainz4::CEntity *Base=(MusicBrainz4::CEntity *)&NonMBTrack;

	os << *Base << std::endl;

	os << "\tTitle:  " << NonMBTrack.Title() << std::endl;
	os << "\tArtist: " << NonMBTrack.Artist() << std::endl;
	os << "\tLength: " << NonMBTrack.Length() << std::endl;

	return os;
}