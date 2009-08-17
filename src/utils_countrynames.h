/* 

static const char *countryNames[][2] = {
	{"BD", "Bangladesh"},
	{"BE", "Belgium"},
	{"BF", "Burkina Faso"},
	{"BG", "Bulgaria"},
	{"BB", "Barbados"},
	{"WF", "Wallis and Futuna Islands"},
	{"BM", "Bermuda"},
	{"BN", "Brunei Darussalam"},
	{"BO", "Bolivia"},
	{"BH", "Bahrain"},
	{"BI", "Burundi"},
	{"BJ", "Benin"},
	{"BT", "Bhutan"},
	{"JM", "Jamaica"},
	{"BV", "Bouvet Island"},
	{"BW", "Botswana"},
	{"WS", "Samoa"},
	{"BR", "Brazil"},
	{"BS", "Bahamas"},
	{"BY", "Belarus"},
	{"BZ", "Belize"},
	{"RU", "Russian Federation"},
	{"RW", "Rwanda"},
	{"RE", "Reunion"},
	{"TM", "Turkmenistan"},
	{"TJ", "Tajikistan"},
	{"RO", "Romania"},
	{"TK", "Tokelau"},
	{"GW", "Guinea-Bissau"},
	{"GU", "Guam"},
	{"GT", "Guatemala"},
	{"GR", "Greece"},
	{"GQ", "Equatorial Guinea"},
	{"GP", "Guadeloupe"},
	{"JP", "Japan"},
	{"GY", "Guyana"},
	{"GF", "French Guiana"},
	{"GE", "Georgia"},
	{"GD", "Grenada"},
	{"GB", "United Kingdom"},
	{"GA", "Gabon"},
	{"SV", "El Salvador"},
	{"GN", "Guinea"},
	{"GM", "Gambia"},
	{"GL", "Greenland"},
	{"GI", "Gibraltar"},
	{"GH", "Ghana"},
	{"OM", "Oman"},
	{"TN", "Tunisia"},
	{"JO", "Jordan"},
	{"HT", "Haiti"},
	{"HU", "Hungary"},
	{"HK", "Hong Kong"},
	{"HN", "Honduras"},
	{"HM", "Heard and Mc Donald Islands"},
	{"VE", "Venezuela"},
	{"PR", "Puerto Rico"},
	{"PW", "Palau"},
	{"PT", "Portugal"},
	{"SJ", "Svalbard and Jan Mayen Islands"},
	{"PY", "Paraguay"},
	{"IQ", "Iraq"},
	{"PA", "Panama"},
	{"PF", "French Polynesia"},
	{"PG", "Papua New Guinea"},
	{"PE", "Peru"},
	{"PK", "Pakistan"},
	{"PH", "Philippines"},
	{"PN", "Pitcairn"},
	{"PL", "Poland"},
	{"PM", "St. Pierre and Miquelon"},
	{"ZM", "Zambia"},
	{"EH", "Western Sahara"},
	{"EE", "Estonia"},
	{"EG", "Egypt"},
	{"ZA", "South Africa"},
	{"EC", "Ecuador"},
	{"IT", "Italy"},
	{"VN", "Viet Nam"},
	{"SB", "Solomon Islands"},
	{"ET", "Ethiopia"},
	{"SO", "Somalia"},
	{"ZW", "Zimbabwe"},
	{"SA", "Saudi Arabia"},
	{"ES", "Spain"},
	{"ER", "Eritrea"},
	{"MD", "Moldova, Republic of"},
	{"MG", "Madagascar"},
	{"MA", "Morocco"},
	{"MC", "Monaco"},
	{"UZ", "Uzbekistan"},
	{"MM", "Myanmar"},
	{"ML", "Mali"},
	{"MO", "Macau"},
	{"MN", "Mongolia"},
	{"MH", "Marshall Islands"},
	{"MK", "Macedonia, The Former Yugoslav Republic of"},
	{"MU", "Mauritius"},
	{"MT", "Malta"},
	{"MW", "Malawi"},
	{"MV", "Maldives"},
	{"MQ", "Martinique"},
	{"MP", "Northern Mariana Islands"},
	{"MS", "Montserrat"},
	{"MR", "Mauritania"},
	{"UG", "Uganda"},
	{"MY", "Malaysia"},
	{"MX", "Mexico"},
	{"IL", "Israel"},
	{"FR", "France"},
	{"IO", "British Indian Ocean Territory"},
	{"SH", "St. Helena"},
	{"FI", "Finland"},
	{"FJ", "Fiji"},
	{"FK", "Falkland Islands (Malvinas)"},
	{"FM", "Micronesia, Federated States of"},
	{"FO", "Faroe Islands"},
	{"NI", "Nicaragua"},
	{"NL", "Netherlands"},
	{"NO", "Norway"},
	{"NA", "Namibia"},
	{"VU", "Vanuatu"},
	{"NC", "New Caledonia"},
	{"NE", "Niger"},
	{"NF", "Norfolk Island"},
	{"NG", "Nigeria"},
	{"NZ", "New Zealand"},
	{"ZR", "Zaire"},
	{"NP", "Nepal"},
	{"NR", "Nauru"},
	{"NU", "Niue"},
	{"CK", "Cook Islands"},
	{"CI", "Cote d'Ivoire"},
	{"CH", "Switzerland"},
	{"CO", "Colombia"},
	{"CN", "China"},
	{"CM", "Cameroon"},
	{"CL", "Chile"},
	{"CC", "Cocos (Keeling) Islands"},
	{"CA", "Canada"},
	{"CG", "Congo"},
	{"CF", "Central African Republic"},
	{"CZ", "Czech Republic"},
	{"CY", "Cyprus"},
	{"CX", "Christmas Island"},
	{"CR", "Costa Rica"},
	{"CV", "Cape Verde"},
	{"CU", "Cuba"},
	{"SZ", "Swaziland"},
	{"SY", "Syrian Arab Republic"},
	{"KG", "Kyrgyzstan"},
	{"KE", "Kenya"},
	{"SR", "Suriname"},
	{"KI", "Kiribati"},
	{"KH", "Cambodia"},
	{"KN", "Saint Kitts and Nevis"},
	{"KM", "Comoros"},
	{"ST", "Sao Tome and Principe"},
	{"SI", "Slovenia"},
	{"KW", "Kuwait"},
	{"SN", "Senegal"},
	{"SM", "San Marino"},
	{"SL", "Sierra Leone"},
	{"SC", "Seychelles"},
	{"KZ", "Kazakhstan"},
	{"KY", "Cayman Islands"},
	{"SG", "Singapore"},
	{"SE", "Sweden"},
	{"SD", "Sudan"},
	{"DO", "Dominican Republic"},
	{"DM", "Dominica"},
	{"DJ", "Djibouti"},
	{"DK", "Denmark"},
	{"VG", "Virgin Islands (British)"},
	{"DE", "Germany"},
	{"YE", "Yemen"},
	{"DZ", "Algeria"},
	{"US", "United States"},
	{"UY", "Uruguay"},
	{"YT", "Mayotte"},
	{"UM", "United States Minor Outlying Islands"},
	{"LB", "Lebanon"},
	{"LC", "Saint Lucia"},
	{"LA", "Lao People's Democratic Republic"},
	{"TV", "Tuvalu"},
	{"TW", "Taiwan"},
	{"TT", "Trinidad and Tobago"},
	{"TR", "Turkey"},
	{"LK", "Sri Lanka"},
	{"LI", "Liechtenstein"},
	{"LV", "Latvia"},
	{"TO", "Tonga"},
	{"LT", "Lithuania"},
	{"LU", "Luxembourg"},
	{"LR", "Liberia"},
	{"LS", "Lesotho"},
	{"TH", "Thailand"},
	{"TF", "French Southern Territories"},
	{"TG", "Togo"},
	{"TD", "Chad"},
	{"TC", "Turks and Caicos Islands"},
	{"LY", "Libyan Arab Jamahiriya"},
	{"VA", "Vatican City State (Holy See)"},
	{"VC", "Saint Vincent and The Grenadines"},
	{"AE", "United Arab Emirates"},
	{"AD", "Andorra"},
	{"AG", "Antigua and Barbuda"},
	{"AF", "Afghanistan"},
	{"AI", "Anguilla"},
	{"VI", "Virgin Islands (U.S.)"},
	{"IS", "Iceland"},
	{"IR", "Iran (Islamic Republic of)"},
	{"AM", "Armenia"},
	{"AL", "Albania"},
	{"AO", "Angola"},
	{"AN", "Netherlands Antilles"},
	{"AQ", "Antarctica"},
	{"AS", "American Samoa"},
	{"AR", "Argentina"},
	{"AU", "Australia"},
	{"AT", "Austria"},
	{"AW", "Aruba"},
	{"IN", "India"},
	{"TZ", "Tanzania, United Republic of"},
	{"AZ", "Azerbaijan"},
	{"IE", "Ireland"},
	{"ID", "Indonesia"},
	{"UA", "Ukraine"},
	{"QA", "Qatar"},
	{"MZ", "Mozambique"},
	{"BA", "Bosnia and Herzegovina"},
	{"CD", "Congo, The Democratic Republic of the"},
	{"CS", "Serbia and Montenegro"},
	{"HR", "Croatia"},
	{"KP", "Korea (North), Democratic People's Republic of"},
	{"KR", "Korea (South), Republic of"},
	{"SK", "Slovakia"},
	{"SU", "Soviet Union (historical, 1922-1991)"},
	{"TL", "East Timor"},
	{"XC", "Czechoslovakia (historical, 1918-1992)"},
	{"XE", "Europe"},
	{"XG", "East Germany (historical, 1949-1990)"},
	{"XU", "[Unknown Country]"},
	{"XW", "[Worldwide]"},
	{"YU", "Yugoslavia (historical, 1918-1992)"},
};

