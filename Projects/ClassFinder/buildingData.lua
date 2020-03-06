print("loaded: buildingData.lua")
local buildings = {
--Building Data

	{
		name = "A.B. Barret Hall",
		thumbnail = "images/buildingsPictures/A.B.BarretHall.png",
		image = "images/buildingsPictures/A.B.BarretHallH.png",
		description = "Dorm"

	},{		
		name = "A.B. Morris Hall",
		thumbnail = "images/buildingsPictures/MorrisHall.png",
		image = "images/buildingsPictures/MorrisHallH.png",
		description = "Dorm"

	},{
		name = "Brown Library",
		thumbnail = "images/buildingsPictures/BrownLibrary.png",
		image = "images/buildingsPictures/BrownLibraryH.png",
		description = "Learning Center, Team 55 Helpdesk, CopyCat"

	},{
		name = "Bennet Gymnasium",
		thumbnail = "images/buildingsPictures/BennetGym.png",
		image = "images/buildingsPictures/BennetGymH.png",
		description = "Enginnering labs"

	},{
		name = "Chapel on the Hill",
		thumbnail = "images/buildingsPictures/ChapelOnTheHill.png",
		image = "images/buildingsPictures/ChapelOnTheHillH.png",
		description = "Outdoor Auditorium"

	},{
		name = "Crutcher Scott Field",
		thumbnail = "images/buildingsPictures/CrutcherScottField.png",
		image = "images/buildingsPictures/CrutcherScottFieldH.png",
		description = "Baseball Field"

	},{
		name = "Cullen Auditorium",
		thumbnail = "images/buildingsPictures/CullenAud.png",
		image = "images/buildingsPictures/CullenAudH.png",
		description = "Auditorium, Cornstone spotlight"

	},{
		name = "Edwards Hall",
		thumbnail = "images/buildingsPictures/EdwardsHall.png",
		image = "images/buildingsPictures/EdwardsHallH.png",
		description = "Sophmore Boys Dorm"

	},{
		name = "Elmer Gray Stadium",
		thumbnail = "images/buildingsPictures/Stadium.png",
		image = "images/buildingsPictures/StadiumH.png",
		description = "Football Stadium"

	},{
		name = "Gardner Hall",
		thumbnail = "images/buildingsPictures/GardnerHall.png",
		image = "images/buildingsPictures/GardnerHallH.png",
		description = "Freshman Girls Dorm"

	},{
		name = "Hardin Administration Building",
		thumbnail = "images/buildingsPictures/AdminBuilding.png",
		image = "images/buildingsPictures/AdminBuildingH.png",
		description = "English Classes and Administrative offices"

	},{
		name = "Hunter Welcome Center",
		thumbnail = "images/buildingsPictures/HunterWelcomeCenter.png",
		image = "images/buildingsPictures/HunterWelcomeCenterH.png",
		description = "Administrative offices and lecture halls"

	},{	
		name = "Mabee Buisness Building(Coba)",
		thumbnail = "images/buildingsPictures/Coba.png",
		image = "images/buildingsPictures/CobaH.png",
		description = "Buissness and IT"

	},{
		name = "Mabee Hall",
		thumbnail = "images/buildingsPictures/MabeeHall.png",
		image = "images/buildingsPictures/MabeeHallH.png",
		description = "Freshman boys dorm"

	},{
		name = "McGlothin Campus Center(The Bean)",
		thumbnail = "images/buildingsPictures/Bean.png",
		image = "images/buildingsPictures/BeanH.png",
		description = "The Bean, ACU Mail, Campus Store, Advising Department"

	},{
		name = "McKinzie Hall",
		thumbnail = "images/buildingsPictures/MckenzieHall.png",
		image = "images/buildingsPictures/MckenzieHall.Pysch.DepH.png",
		description = "Freshman Boys Dorm"

	},{
		name = "Medical and Counseling Care Center",
		thumbnail = "images/buildingsPictures/Medical.png",
		image = "images/buildingsPictures/MedicalH.png",
		description = "Student Clinic"

	},{
		name = "Moody Coliseum",
		thumbnail = "images/buildingsPictures/MoodyColiseum.png",
		image = "images/buildingsPictures/MoodyColiseumH.png",
		description = "Basketball stadium, Chapel Auditorium"

	},{
		name = "Nelson Hall",
		thumbnail = "images/buildingsPictures/NelsonHall.png",
		image = "images/buildingsPictures/NelsonHallH.png",
		description = "Freshman Girls Dorm"

	},{
		name = "Onstead-Packer Biblical Studies Building",
		thumbnail = "images/buildingsPictures/BibleBuilding.png",
		image = "images/buildingsPictures/BibleBuildingH.png",
		description = "Bible Lecture Halls"

	},{
		name = "Onstead Science Center",
		thumbnail = "images/buildingsPictures/Onstead.png",
		image = "images/buildingsPictures/OnsteadH.png",
		description = "Sciences Classrooms, Math, Bio..."

	},{
		name = "Phillips Education Building",
		thumbnail = "images/buildingsPictures/Education.png",
		image = "images/buildingsPictures/EducationH.png",
		description = "Early Education, and Teaching"

	},{
		name = "Packer Research Center",
		thumbnail = "images/buildingsPictures/Packer.png",
		image = "images/buildingsPictures/PackerH.png",
		description = "Early Education, and Teaching"

	},{
		name = "Police Department",
		thumbnail = "images/buildingsPictures/Police.png",
		image = "images/buildingsPictures/PoliceH.png",
		description = "ACU PoliceDepartment \nIn case of emrgency  (325)-674-2911"

	},{
		name = "Student Recreation and Wellness Center",
		thumbnail = "images/buildingsPictures/Gym.png",
		image = "images/buildingsPictures/Gym.png",
		description = "Basketball Courts, Pools, Rawuet Ball, Weights"

	},{
		name = "Sherrod Building",
		thumbnail = "images/buildingsPictures/Sherrod.png",
		image = "images/buildingsPictures/SherrodH.png",
		description = "Art Building"

	},{
		name = "Sikes Hall",
		thumbnail = "images/buildingsPictures/SikesHall.png",
		image = "images/buildingsPictures/SikesHallH.png",
		description = "Freshman Girls Dorm"

	},{
		name = "Teague Center",
		thumbnail = "images/buildingsPictures/TeagueCenter.png",
		image = "images/buildingsPictures/TeagueCenterH.png",
		description = "Tennis Building"

	},{
		name = "Sewell Theatre",
		thumbnail = "images/buildingsPictures/Sewell.png",
		image = "images/buildingsPictures/SewellH.png",
		description = "Theare Building"

	},{
		name = "Universriy Park Apartments",
		thumbnail = "images/buildingsPictures/Uni.Park.png",
		image = "images/buildingsPictures/Uni.ParkH.png",
		description = "Jr. Sr. on Campus Apts."

	},{
		name = "Wally Bullington Football Practice Facility",
		thumbnail = "images/buildingsPictures/Stadium.png",
		image = "images/buildingsPictures/wallyH.png",
		description = "Practice Football Field"

	},{
		name = "Wells Field",
		thumbnail = "images/buildingsPictures/WellsField.png",
		image = "images/buildingsPictures/WellsFieldH.png",
		description = "Rec. Field"

	},{
		name = "Williams Performing Arts Center",
		thumbnail = "images/buildingsPictures/WPAC.png",
		image = "images/buildingsPictures/WPACH.png",
		description = "Theatre Building"

	},{
		name = "Zellner Hall",
		thumbnail = "images/buildingsPictures/ZellnerHall.png",
		image = "images/buildingsPictures/ZellnerHallH.png",
		description = "IT offices, Networking and Hardware HQ"
	}
}

return buildings