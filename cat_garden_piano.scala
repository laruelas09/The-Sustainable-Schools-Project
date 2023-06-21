object SustainableSchools {
  // declare variables
  var totalSchools: Integer = 0
  var solarPanelsInstalled: Integer = 0
  var windTurbinesInstalled: Integer = 0

// main function
  def main(args: Array[String]): Unit = {
    
    // Get the total number of schools
    println("Please enter total number of schools: ")
    totalSchools = scala.io.StdIn.readInt()
    
    // Calculate the number of solar panels and wind turbines to install
    installSolarPanels(totalSchools)
    installWindTurbines(totalSchools)
    
    // Print out the results
    println(s"Solar panels installed: $solarPanelsInstalled")
    println(s"Wind turbines installed: $windTurbinesInstalled")
    
    // Call the energy savings function
    energySavings()
  }
  
  // Function to install the solar panels
  def installSolarPanels(totalSchools: Integer): Unit = {
    solarPanelsInstalled = totalSchools * 5
  }
  
  // Function to install the wind turbines
  def installWindTurbines(totalSchools: Integer): Unit = {
    windTurbinesInstalled = totalSchools * 10
  }
  
  // Function to calculate the energy savings
  def energySavings(): Unit = {
    val totalEnergySaved = (solarPanelsInstalled * 2) + (windTurbinesInstalled * 3)
    println(s"Total energy saved by the Sustainable Schools Project: $totalEnergySaved KWh")
  }
  
}