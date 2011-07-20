#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "musicbrainz4/mb4_c.h"

int main(int argc, const char *argv[])
{
	Mb4Query Query;

	argc=argc;
	argv=argv;

	Query=mb4_query_new("searchcexample-1.0",NULL,0);
	if (Query)
	{
		char **ParamNames;
		char **ParamValues;
		Mb4Metadata Metadata;
		char ErrorMessage[256];
		tQueryResult Result;
		int HTTPCode;

		ParamNames=malloc(2*sizeof(char *));
		ParamNames[0]=malloc(256);
		ParamNames[1]=malloc(256);
		ParamValues=malloc(2*sizeof(char *));
		ParamValues[0]=malloc(256);
		ParamValues[1]=malloc(256);

		strcpy(ParamNames[0],"query");
		strcpy(ParamValues[0],"artist:john");

		strcpy(ParamNames[1],"limit");
		strcpy(ParamValues[1],"10");

		Metadata=mb4_query_query(Query,"artist","","",2,ParamNames,ParamValues);

		Result=mb4_query_get_lastresult(Query);
		HTTPCode=mb4_query_get_lasthttpcode(Query);

		mb4_query_get_lasterrormessage(Query,ErrorMessage,sizeof(ErrorMessage));
		printf("Result: %d\nHTTPCode: %d\nErrorMessage: '%s'\n",Result,HTTPCode,ErrorMessage);

		if (Metadata)
		{
			int ThisArtist;
			Mb4ArtistList ArtistList=mb4_metadata_get_artistlist(Metadata);

			printf("Found %d artist(s)\n",mb4_artist_list_size(ArtistList));

			for (ThisArtist=0;ThisArtist<mb4_artist_list_size(ArtistList);ThisArtist++)
			{
				Mb4Artist Artist=mb4_artist_list_item(ArtistList,ThisArtist);
				if (Artist)
				{
					int count;
					char Name[256];
					char Value[256];
					int NumExtAttrs=mb4_entity_ext_attributes_size(Artist);
					int NumExtElements=mb4_entity_ext_elements_size(Artist);

					printf("%d attrs, %d elements\n",NumExtAttrs,NumExtElements);

					for (count=0;count<NumExtAttrs;count++)
					{
						mb4_entity_ext_attribute_name(Artist,count,Name,sizeof(Name));
						mb4_entity_ext_attribute_value(Artist,count,Value,sizeof(Value));

						printf("Attr '%s' = '%s'\n",Name,Value);
					}

					for (count=0;count<NumExtElements;count++)
					{
						mb4_entity_ext_element_name(Artist,count,Name,sizeof(Name));
						mb4_entity_ext_element_value(Artist,count,Value,sizeof(Value));

						printf("Element '%s' = '%s'\n",Name,Value);
					}

					mb4_artist_get_name(Artist,Name,sizeof(Name));
					printf("Artist is '%s'\n",Name);

					mb4_artist_get_sortname(Artist,Name,sizeof(Name));
					printf("Artist sort is '%s'\n",Name);

					mb4_artist_delete(Artist);
				}
				else
				{
					printf("Couldn't get artist %d\n",ThisArtist);
				}
			}

			mb4_metadata_delete(Metadata);
		}

		free(ParamValues[1]);
		free(ParamValues[0]);
		free(ParamValues);
		free(ParamNames[1]);
		free(ParamNames[0]);
		free(ParamNames);

		mb4_query_delete(Query);
	}

	return 0;
}