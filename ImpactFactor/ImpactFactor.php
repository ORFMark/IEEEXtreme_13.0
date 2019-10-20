<?php
$handle = fopen ("php://stdin","r");
$lines = fgets($handle);
$input = array();
for ($i = 0; $i < $lines; $i++) {
    array_push($input, json_decode(fgets($handle), true));
}

// extract the publication journal IDs and years
$journals = array();
foreach ($input[0]["publications"] as $publication) {
	$entry = array(); // entry to journals
	$years = array(2017, 2018); // arrays for articles
	$articles = array();
	$totalArticles = 0;
    foreach ($publication["articleCounts"] as $articleCount) {
    	$article = array();
    	if (in_array($articleCount["year"], $years)) {
        	$totalArticles += $articleCount["articleCount"];
        	$article["citations"] = 0;
        	$article["articleCount"] = $articleCount["articleCount"];
        	$article["year"] = $articleCount["year"];
    	}
    	array_push($articles, $article);
    }
    $entry["title"] = $publication["publicationTitle"];
    $entry["number"] = $publication["publicationNumber"];
    $entry["numArticles"] = $totalArticles;
    $entry["articles"] = $articles;
    $entry["years"] = $years;
    $entry["citationsMade"] = 0;

    array_push($journals, $entry);
}

// loop through each paper
for ($i = 1; $i < $lines; $i++) {
	// loop through citations for paper
	foreach ($input[$i]["paperCitations"]["ieee"] as $citation) {
		// loop through each journal
		//var_dump($citation);
		for ($j = 0; $j < count($journals); $j++) {
			if ($citation["publicationNumber"] == $journals[$j]["number"]) {
				//echo "made it";
				// check if the years are consistent
				// usage: in_array(needle, haystack)
				for ($k = 0; $k < count($journals[$j]["articles"]); $k++) {
					if ($citation["year"] == $journals[$j]["articles"][$k]["year"]) {

						$journals[$j]["articles"][$k]["citations"]++; // increment citations for
						                             				  // current journal article
						$journals[$j]["citationsMade"]++; // increment for journal
						if ($journals[$j]["articles"][$k]["citations"] ==
							$journals[$j]["articles"][$k]["articleCount"])
							break; // do not allow over-citation
						       	   // reference a given journal
					}
				}
			}
		}
	}
}

// calculate the impact factor for each journal and report to the console
// ORDER BY DESCENDING IMPACT FACTOR
$impactFactorStrings = array();
foreach ($journals as $journal) {
	$impactFactor = $journal["citationsMade"] / $journal["numArticles"];
	$entry = array();
	// output to the string array
	$entry["impactFactor"] = $impactFactor;
	$entry["txt"] = $journal["title"] . ": " . number_format(round($impactFactor,2),2) . "\n";
	array_push($impactFactorStrings, $entry);
}
rsort($impactFactorStrings); // sort high to low
//var_dump($impactFactorStrings);
foreach ($impactFactorStrings as $impactFactor) {
	print($impactFactor["txt"]);
}

//var_dump($journals);
?>