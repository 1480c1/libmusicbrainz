/*
 * MusicBrainz -- The Internet music metadatabase
 *
 * Copyright (C) 2006 Lukas Lalinsky
 *  
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * 
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * $Id$
 */ 

#ifndef __MUSICBRAINZ3_RELEASE_H__
#define __MUSICBRAINZ3_RELEASE_H__

#include <string>
#include <musicbrainz3/musicbrainz.h>
#include <musicbrainz3/entity.h>
#include <musicbrainz3/lists.h>

namespace MusicBrainz
{

	class Artist;
	
	/**
	 * Represents a Release.
	 *
	 * A release within MusicBrainz is an Entity which contains Track
	 * objects.  Releases may be of more than one type: There can be albums,
	 * singles, compilations, live recordings, official releases, bootlegs
	 * etc.
	 *
	 * @note: The current MusicBrainz server implementation supports only a
	 * limited set of types.
	 */
	class MB_API Release : public Entity
	{
	public:
	
		static const std::string TYPE_NONE;
	
		static const std::string TYPE_ALBUM;
		static const std::string TYPE_SINGLE;
		static const std::string TYPE_EP;
		static const std::string TYPE_COMPILATION;	
		static const std::string TYPE_SOUNDTRACK;
		static const std::string TYPE_SPOKENWORD;
		static const std::string TYPE_INTERVIEW;
		static const std::string TYPE_AUDIOBOOK;
		static const std::string TYPE_LIVE;
		static const std::string TYPE_REMIX;	
		static const std::string TYPE_OTHER;

		static const std::string TYPE_OFFICIAL;
		static const std::string TYPE_PROMOTION;
		static const std::string TYPE_BOOTLEG; 	
	
		/**
		 * Constructor.
		 *
		 * @param id a string containing an absolute URI 
		 * @param title a string containing the title 
		 */
		Release(const std::string &id = std::string(),
				const std::string &title = std::string());
		
		/**
		 * Destructor.
		 */
		~Release();
		
		/**
		 * Returns the track's title.
		 *
		 * The style and format of this attribute is specified by the
		 * style guide.
		 *
		 * @return a string containing an absolute URI
		 * 
		 * @see <a href="http://musicbrainz.org/style.html">The MusicBrainz
		 *		Style Guidelines</a> 
		 */
		std::string getTitle() const;
		
		/**
		 * Sets the release's title.
		 *
		 * @param title: a string containing the release's title
		 *
		 * @see getTitle
		 */
		void setTitle(const std::string &title);

		/**
		 * Returns the language used in release and track titles.
		 *
		 * To represent the language, the ISO-639-2/T standard is used,
		 * which provides three-letter terminological language codes like
		 * "ENG", "DEU", "JPN", "KOR", "ZHO" or "YID".
		 *
		 * Note that this refers to release and track \e titles, not
		 * lyrics.
		 *
		 * @return a string containing the language code
		 *
		 * @see getLanguageName 
		 */
		std::string getTextLanguage() const;

		/**
		 * Sets the language used in releaes and track titles.
		 *
		 * @param language a string containing a language code
		 *
		 * @see getTextLanguage 
		 */
		void setTextLanguage(const std::string &language);

		/**
		 * Returns the script used in release and track titles.
		 *
		 * To represent the script, ISO-15924 script codes are used.
		 * Valid codes are, among others: "Latn", "Cyrl", "Hans", "Hebr"
		 * 
		 * Note that this refers to release and track \e titles, not
		 * lyrics.
		 * 
		 * @return: a string containing the script code
		 *
		 * @see: getScriptName 
		 */
		std::string getTextScript() const;

		/**
		 * Sets the script used in releaes and track titles.
		 *
		 * @param script a string containing a script code
		 *
		 * @see getTextScript 
		 */
		void setTextScript(const std::string &script);

		/**
		 * Returns the main artist of this release.
		 *
		 * @return a pointer to Artist object, or NULL 
		 */
		Artist *getArtist();
		
		/** 
		 * Sets this release's main artist.
		 *
		 * @param artist a pointer to Artist object 
		 */
		void setArtist(Artist *artist);

		/**
		 * Returns the Amazon shop identifier (ASIN).
		 *
		 * The ASIN is a 10-letter code (except for books) assigned
		 * by Amazon, which looks like 'B000002IT2' or 'B00006I4YD'.
		 * 
		 * @return a string containing the ASIN
		 */
		std::string getAsin() const;
		
		/**
		 * Sets the Amazon shop identifier (ASIN).
		 * 
		 * @param asin a string containing the ASIN
		 *
		 * @see getAsin
		 */
		void setAsin(const std::string &asin);
		
		/**
		 * Returns the tracks this release contains.
		 *
		 * @return a list containing pointers to Track objects
		 *
		 * @see getTracksOffset
		 */
		TrackList &getTracks();

		/**
		 * Returns the offset of the track list.
		 * 
		 * This is used if the track list is incomplete (ie. the web
		 * service only returned part of the tracks on this release).
		 * Note that the offset value is zero-based, which means track
		 * \a 0 is the first track.
		 *
		 * @return an integer containing the offset
		 *
		 * @see getTracks 
		 */
		int getTracksOffset() const;
		
		/**
		 * Sets the offset of the track list.
		 *
		 * @param offset an integer containing the offset
		 *
		 * @see getTracksOffset 
		 */
		void setTracksOffset(const int offset);
		
		/**
		 * Returns the discs associated with this release.
		 *
		 * Discs are currently containers for MusicBrainz DiscIDs.
		 * Note that under rare circumstances (identical TOCs), a
		 * DiscID could be associated with more than one release.
		 *
		 * @return: a list of pointers to Disc objects
		 */
		DiscList &getDiscs();
		
		/**
		 * Returns the list of release events.
		 *
		 * A Release may contain a list of so-called release events,
		 * each represented using a ReleaseEvent object. Release
		 * evens specify where and when this release was, well, released.
		 * 
		 * @return: a list of pointers to ReleaseEvent objects
		 */
		ReleaseEventList &getReleaseEvents();
		
	private:
		
		std::string title;
		std::string textLanguage;
		std::string textScript;
		std::string asin;
		Artist *artist;
		TrackList tracks;
		int tracksOffset;
		DiscList discs;
		ReleaseEventList releaseEvents;
	};
	
}

#endif

