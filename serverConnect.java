@RequestMapping(value = "user/getOnlineApplicationsList", produces = "XML/Text; charset=utf-8", method = RequestMethod.POST)
	public @ResponseBody String getOnlineApplicationsList(HttpSession session, HttpServletRequest request,
			@RequestParam("status") int status, @RequestParam("fullname") String fullname,
			@RequestParam("privateNumber") String privateNumber, @RequestParam("phoneNumber") String phoneNumber,
			@RequestParam("applicationIdFrom") String applicationIdFrom,
			@RequestParam("applicationIdTo") String applicationIdTo,
			// @RequestParam("dateFrom") String timeFrom,
			// @RequestParam("dateTo") String timeTo,
			@RequestParam("order") int order, @RequestParam("companyId") int companyId) {
		try {
			TimeFunctions tf = new TimeFunctions();
			StringBuilder ret = new StringBuilder();
			List<OnlineApplication> onlineAppList = new ArrayList<OnlineApplication>();
			List<OnlineApplicationForConsumerLoan> onlineAppListCL = new ArrayList<OnlineApplicationForConsumerLoan>();

			if (companyId == 3) {
				onlineAppList = onlineAppService.getOnlineApps(fullname, privateNumber,
						tf.dateStrToMilliseconds("11-11-1111"), tf.dateStrToMilliseconds("11-11-9999"), 0, 250, order,
						status, phoneNumber, applicationIdFrom, applicationIdTo);
			}
			else if (companyId == 2) {
				onlineAppListCL = onlineAppService.getConsumerOnlineApps(fullname, privateNumber,
						tf.dateStrToMilliseconds("11-11-1111"), tf.dateStrToMilliseconds("11-11-9999"), 0, 250, order,
						status, phoneNumber, applicationIdFrom, applicationIdTo);
			}
		
			else {
				onlineAppList = onlineAppService.getOnlineApps(fullname, privateNumber,
						tf.dateStrToMilliseconds("11-11-1111"), tf.dateStrToMilliseconds("11-11-9999"), 0, 250, order,
						status, phoneNumber, applicationIdFrom, applicationIdTo);
				onlineAppListCL = onlineAppService.getConsumerOnlineApps(fullname, privateNumber,
						tf.dateStrToMilliseconds("11-11-1111"), tf.dateStrToMilliseconds("11-11-9999"), 0, 250, order,
						status, phoneNumber, applicationIdFrom, applicationIdTo);
			}
			for (OnlineApplication onlineApp : onlineAppList) {
				if (onlineApp.getStatus() == 0) {
					ret.append("<br>"
							+ "<table style=\"width:100%; height: 180px; border: 1px solid black; text-align:center; border-collapse: collapse; spacing: 5px;\">"
							+ "<tr style=\"background-color:#85C1E9; height: 20px; font-weight: bold;\">"
							+ "<td>ID</td>" + "<td>თანხა</td>" + "<td>პერიოდი</td>" + "<td>სახელი გვარი</td>"
							+ "<td>დაბ.თარიღი</td>" + "<td>პირადი ნომ.</td>" + "<td>მობილური</td>"
							+ "<td>სამუშაო სფერო</td>" + "<td>კომპანია</td>" + "<td>პოზიცია</td>" + "<td>ხელფასი</td>"
							+ "<td>სტატუსი</td>" + "</tr>" + "<tr>" + "<td>" + onlineApp.getOnlineAppId() + "</td>"
							+ "<td>" + Math.round(onlineApp.getAmount().doubleValue() * 100.0) / 100.0 + "</td>"
							+ "<td>" + onlineApp.getPeriod() + "</td>" + "<td>" + onlineApp.getFullname() + "</td>"
							+ "<td>" + onlineApp.getBirthdate() + "</td>" + "<td>" + onlineApp.getPersonalNumber()
							+ "</td>" + "<td>" + onlineApp.getMobilephone() + "</td>" + "<td>"
							+ onlineApp.getWorkField() + "</td>" + "<td>" + onlineApp.getCompanyName() + "</td>"
							+ "<td>" + onlineApp.getPosition() + "</td>" + "<td>" + onlineApp.getSalary() + "</td>"
							+ "<td>" + getNameForStatus(onlineApp.getStatus()) + "</td>" + "</tr>"
							+ "<tr style=\"background-color:#85C1E9; height: 20px; font-weight: bold;\">"
							+ "<td>მუშ.ხან.</td>" + "<td>დამ.შემოსავალი</td>" + "<td>თვ.გადასახდელი</td>"
							+ "<td>ოჯახ.მდგომ.</td>" + "<td>შვილები</td>" + "<td>დასაქ.ოჯახ.წევრები</td>"
							+ "<td>საერთო შემოსავალი</td>" + "<td>თარიღი</td>" +  "<td>ინკასო</td>" +
							"<td>დადასტურება</td>"+ "<td>უარყოფა</td>" + "<td>წაშლა</td>" + "</tr>" + "<tr>" + "<td>"
							+ onlineApp.getWorkTime() + "</td>" + "<td>" + onlineApp.getAdditionalIncome() + "</td>"
							+ "<td>" + onlineApp.getLoanFreqAmount() + "</td>" + "<td>" + onlineApp.getMaritalStatus()
							+ "</td>" + "<td>" + onlineApp.getChildren() + "</td>" + "<td>"
							+ onlineApp.getWorkingRelatives() + "</td>" + "<td>" + onlineApp.getTotalIncome() + "</td>"
							+ "<td>" + tf.millisecondsToDateStr(onlineApp.getAdditionTime()) + "</td>"
							+ "<td>"+(onlineApp.isIncaso() ? "ინკასო":"არ ადევს")+"</td>" + "<td bgcolor=\"lightgreen\" onclick=\"approveApplication(" + onlineApp.getOnlineAppId()
							+ "," + onlineApp.getCompany() + ")\"><img height=\"20px\" width=\"20px\" src=\""
							+ request.getContextPath() + "/resources/images/accept.png\"></td>"
							+ "<td bgcolor=\"LightCoral\" onclick=\"rejectApplication(" + onlineApp.getOnlineAppId()
							+ "," + onlineApp.getCompany() + ")\"><img height=\"20px\" width=\"20px\" src=\""
							+ request.getContextPath() + "/resources/images/reject.png\"></td>"
							+ "<td bgcolor=\"silver\" onclick=\"deleteApplication(" + onlineApp.getOnlineAppId() + ","
							+ onlineApp.getCompany() + ")\"><img height=\"20px\" width=\"20px\" src=\""
							+ request.getContextPath() + "/resources/images/delete.png\"></td>" + "</tr>" + ""
							+ "<tr><td colspan=\"3\">" + onlineApp.getLoanPurpose() + "</td><td colspan=\"5\">" + onlineApp.getBranch() + "</td></tr></table>" + "<br>");
				} else if (onlineApp.getStatus() == 1) {
					ret.append("<br>"
							+ "<table style=\"width:100%; height: 180px; border: 1px solid black; text-align:center; border-collapse: collapse; spacing: 5px;\">"
							+ "<tr style=\"background-color:#85C1E9; height: 20px; font-weight: bold;\">"
							+ "<td>ID</td>" + "<td>თანხა</td>" + "<td>პერიოდი</td>" + "<td>სახელი გვარი</td>"
							+ "<td>დაბ.თარიღი</td>" + "<td>პირადი ნომ.</td>" + "<td>მობილური</td>"
							+ "<td>სამუშაო სფერო</td>" + "<td>კომპანია</td>" + "<td>პოზიცია</td>" + "<td>ხელფასი</td>"
							+ "<td>სტატუსი</td>" + "</tr>" + "<tr>" + "<td>" + onlineApp.getOnlineAppId() + "</td>"
							+ "<td>" + Math.round(onlineApp.getAmount().doubleValue() * 100.0) / 100.0 + "</td>"
							+ "<td>" + onlineApp.getPeriod() + "</td>" + "<td>" + onlineApp.getFullname() + "</td>"
							+ "<td>" + onlineApp.getBirthdate() + "</td>" + "<td>" + onlineApp.getPersonalNumber()
							+ "</td>" + "<td>" + onlineApp.getMobilephone() + "</td>" + "<td>"
							+ onlineApp.getWorkField() + "</td>" + "<td>" + onlineApp.getCompanyName() + "</td>"
							+ "<td>" + onlineApp.getPosition() + "</td>" + "<td>" + onlineApp.getSalary() + "</td>"
							+ "<td>" + getNameForStatus(onlineApp.getStatus()) + "</td>" + "</tr>"
							+ "<tr style=\"background-color:#85C1E9; height: 20px; font-weight: bold;\">"
							+ "<td>მუშ.ხან.</td>" + "<td>დამ.შემოსავალი</td>" + "<td>თვ.გადასახდელი</td>"
							+ "<td>ოჯახ.მდგომ.</td>" + "<td>შვილები</td>" + "<td>დასაქ.ოჯახ.წევრები</td>"
							+ "<td>საერთო შემოსავალი</td>" + "<td>თარიღი</td>" + "<td>ინკასო</td>"
							+ "<td align=\"center\">კომენტარები</td><td align=\"center\">აპლიკაციის დამატება</td><td align=\"center\">აპლიკაციის უარყოფა</td>"
							+ "</tr>" + "<tr>" + "<td>" + onlineApp.getWorkTime() + "</td>" + "<td>"
							+ onlineApp.getAdditionalIncome() + "</td>" + "<td>" + onlineApp.getLoanFreqAmount()
							+ "</td>" + "<td>" + onlineApp.getMaritalStatus() + "</td>" + "<td>"
							+ onlineApp.getChildren() + "</td>" + "<td>" + onlineApp.getWorkingRelatives() + "</td>"
							+ "<td>" + onlineApp.getTotalIncome() + "</td>" + "<td>"
							+ tf.millisecondsToDateStr(onlineApp.getAdditionTime()) +
							 "<td>"+(onlineApp.isIncaso() ? "ინკასო":"არ ადევს")+"</td>"
							+ "</td><td onclick=\"triggerComments(" + onlineApp.getOnlineAppId() + ","
							+ onlineApp.getCompany() + ")\"><img height=\"20px\" width=\"20px\" src=\""
							+ request.getContextPath() + "/resources/images/comment.png\"></td>"
							+ "<td bgcolor=\"lightgreen\" onclick=\"acceptApplication(" + onlineApp.getOnlineAppId()
							+ "," + onlineApp.getCompany() + ")\"><img height=\"20px\" width=\"20px\" src=\""
							+ request.getContextPath() + "/resources/images/accept.png\"></td>"
							+ "<td bgcolor=\"LightCoral\" onclick=\"rejectApplication(" + onlineApp.getOnlineAppId()
							+ "," + onlineApp.getCompany() + ")\"><img height=\"20px\" width=\"20px\" src=\""
							+ request.getContextPath() + "/resources/images/reject.png\"></td>" + "</tr>"
							+ "<tr><td colspan=\"3\">" + onlineApp.getLoanPurpose() + "</td><td colspan=\"5\">" + onlineApp.getBranch() + "</td></tr></table>" + "</table>"
							+ "<br>");
				} else {
					ret.append("<br>"
							+ "<table style=\"width:100%; height: 180px; border: 1px solid black; text-align:center; border-collapse: collapse; spacing: 5px;\">"
							+ "<tr style=\"background-color:#85C1E9; height: 20px; font-weight: bold;\">"
							+ "<td>ID</td>" + "<td>თანხა</td>" + "<td>პერიოდი</td>" + "<td>სახელი გვარი</td>"
							+ "<td>დაბ.თარიღი</td>" + "<td>პირადი ნომ.</td>" + "<td>მობილური</td>"
							+ "<td>სამუშაო სფერო</td>" + "<td>კომპანია</td>" + "<td>პოზიცია</td>" + "<td>ხელფასი</td>"
							+ "<td>სტატუსი</td>" + "</tr>" + "<tr>" + "<td>" + onlineApp.getOnlineAppId() + "</td>"
							+ "<td>" + Math.round(onlineApp.getAmount().doubleValue() * 100.0) / 100.0 + "</td>"
							+ "<td>" + onlineApp.getPeriod() + "</td>" + "<td>" + onlineApp.getFullname() + "</td>"
							+ "<td>" + onlineApp.getBirthdate() + "</td>" + "<td>" + onlineApp.getPersonalNumber()
							+ "</td>" + "<td>" + onlineApp.getMobilephone() + "</td>" + "<td>"
							+ onlineApp.getWorkField() + "</td>" + "<td>" + onlineApp.getCompanyName() + "</td>"
							+ "<td>" + onlineApp.getPosition() + "</td>" + "<td>" + onlineApp.getSalary() + "</td>"
							+ "<td>" + getNameForStatus(onlineApp.getStatus()) + "</td>" + "</tr>"
							+ "<tr style=\"background-color:#85C1E9; height: 20px; font-weight: bold;\">"
							+ "<td>მუშ.ხან.</td>" + "<td>დამ.შემოსავალი</td>" + "<td>თვ.გადასახდელი</td>"
							+ "<td>ოჯახ.მდგომ.</td>" + "<td>შვილები</td>" + "<td>დასაქ.ოჯახ.წევრები</td>"
							+ "<td>საერთო შემოსავალი</td>" + "<td>თარიღი</td>" + "<td>ინკასო</td>"
							+ "<td colspan=\"3\" align=\"center\">კომენტარები</td>" + "</tr>" + "<tr>" + "<td>"
							+ onlineApp.getWorkTime() + "</td>" + "<td>" + onlineApp.getAdditionalIncome() + "</td>"
							+ "<td>" + onlineApp.getLoanFreqAmount() + "</td>" + "<td>" + onlineApp.getMaritalStatus()
							+ "</td>" + "<td>" + onlineApp.getChildren() + "</td>" + "<td>"
							+ onlineApp.getWorkingRelatives() + "</td>" + "<td>" + onlineApp.getTotalIncome() + "</td>"
							+ "<td>" + tf.millisecondsToDateStr(onlineApp.getAdditionTime()) + "</td>" +
							"<td>"+(onlineApp.isIncaso() ? "ინკასო":"არ ადევს")+"</td>"
							+ "<td colspan=\"3\" onclick=\"triggerComments(" + onlineApp.getOnlineAppId() + ","
							+ onlineApp.getCompany() + ")\"><img height=\"20px\" width=\"20px\" src=\""
							+ request.getContextPath() + "/resources/images/comment.png\"></td>"
							+ ((onlineApp.getStatus() != 2) ? "<td colspan=\"3\" onclick=\"changeStatus("
									+ onlineApp.getOnlineAppId() + "," + onlineApp.getCompany() + "," + 0
									+ ")\"><img height=\"20px\" width=\"20px\" src=\"" + request.getContextPath()
									+ "/resources/images/resume.png\" title=\"აპლიკაციაში დაბრუნება\"></td>" : "")
							+ "</tr>" + "<tr><td colspan=\"3\">" + onlineApp.getLoanPurpose() + "</td><td colspan=\"5\">" + onlineApp.getBranch() + "</td></tr></table>"
							+ "</table>" + "<br>");
				}
			}
			for (OnlineApplicationForConsumerLoan onlineApp : onlineAppListCL) {
				// TODO: change below
				int consCompId = 2;
				if (onlineApp.getStatus() == 0) {
					ret.append("<br>"
							+ "<table style=\"width:100%; height: 180px; border: 1px solid black; text-align:center; border-collapse: collapse; spacing: 5px;\">"
							+ "<tr style=\"background-color:Coral; height: 20px; font-weight: bold;\">" + "<td>ID</td>"
							+ "<td>თანხა</td>" + "<td>პერიოდი</td>" + "<td>სახელი გვარი</td>" + "<td>დაბ.თარიღი</td>"
							+ "<td>პირადი ნომ.</td>" + "<td>მობილური</td>" + "<td>სამუშაო სფერო</td>"
							+ "<td>კომპანია</td>" + "<td>პოზიცია</td>" + "<td>ხელფასი</td>" + "<td>სტატუსი</td>"
							+ "</tr>" + "<tr>" + "<td>" + onlineApp.getId() + "</td>" + "<td>"
							+ Math.round(onlineApp.getLoanAmount() * 100.0) / 100.0 + "</td>" + "<td>"
							+ onlineApp.getLoanPeriod() + "</td>" + "<td>" + onlineApp.getName() + "</td>" + "<td>"
							+ onlineApp.getBirthDate() + "</td>" + "<td>" + onlineApp.getPrivateNumber() + "</td>"
							+ "<td>" + onlineApp.getMobileNumber() + "</td>" + "<td>" + onlineApp.getWorkSphere()
							+ "</td>" + "<td>" + onlineApp.getCompanyName() + "</td>" + "<td>"
							+ onlineApp.getWorkPosition() + "</td>" + "<td>" + onlineApp.getSalary() + "</td>" + "<td>"
							+ getNameForStatus(onlineApp.getStatus()) + "</td>" + "</tr>"
							+ "<tr style=\"background-color:Coral; height: 20px; font-weight: bold;\">"
							+ "<td>მუშ.ხან.</td>" + "<td>დამ.შემოსავალი</td>" + "<td>თვ.გადასახდელი</td>"
							+ "<td>ოჯახ.მდგომ.</td>" + "<td>შვილები</td>" + "<td>დასაქ.ოჯახ.წევრები</td>"
							+ "<td>საერთო შემოსავალი</td>" + "<td>თარიღი</td>" + "<td>ინკასო</td>" + "<td>დადასტურება</td>"
							+ "<td>უარყოფა</td>" + "<td>წაშლა</td>" + "</tr>" + "<tr>" + "<td>"
							+ onlineApp.getWorkPeriod() + "</td>" + "<td>" + onlineApp.getOtherIncome() + "</td>"
							+ "<td>" + onlineApp.getAmountToPayOnOtherLoans() + "</td>" + "<td>"
							+ onlineApp.getMaritalStatus() + "</td>" + "<td>" + onlineApp.getNumberOfChildren()
							+ "</td>" + "<td>" + onlineApp.getEmployedFamilyMembers() + "</td>" + "<td>"
							+ onlineApp.getTotalFamilyIncome() + "</td>" + "<td>"
							+ tf.millisecondsToDateStr(onlineApp.getAdditionTime()) + "</td>" +
							"<td>"+(onlineApp.isIncaso() ? "ინკასო":"არ ადევს")+"</td>"
							+ "<td bgcolor=\"lightgreen\" onclick=\"approveApplication(" + onlineApp.getId() + ","
							+ consCompId + ")\"><img height=\"20px\" width=\"20px\" src=\"" + request.getContextPath()
							+ "/resources/images/accept.png\"></td>"
							+ "<td bgcolor=\"LightCoral\" onclick=\"rejectApplication(" + onlineApp.getId() + ","
							+ consCompId + ")\"><img height=\"20px\" width=\"20px\" src=\"" + request.getContextPath()
							+ "/resources/images/reject.png\"></td>"
							+ "<td bgcolor=\"silver\" onclick=\"deleteApplication(" + onlineApp.getId() + ","
							+ consCompId + ")\"><img height=\"20px\" width=\"20px\" src=\"" + request.getContextPath()
							+ "/resources/images/delete.png\"></td>" + "</tr>"
							+ "<tr><td colspan=\"3\">"+onlineApp.getLoanPurpose()+"</td><td colspan=\"5\" align=\"left\"> " + onlineApp.getBranchOfficeName() + "</td></tr>"
							+ "</table>" + "<br>");
				} else if (onlineApp.getStatus() == 1) {
					ret.append("<br>"
							+ "<table style=\"width:100%; height: 180px; border: 1px solid black; text-align:center; border-collapse: collapse; spacing: 5px;\">"
							+ "<tr style=\"background-color:Coral; height: 20px; font-weight: bold;\">" + "<td>ID</td>"
							+ "<td>თანხა</td>" + "<td>პერიოდი</td>" + "<td>სახელი გვარი</td>" + "<td>დაბ.თარიღი</td>"
							+ "<td>პირადი ნომ.</td>" + "<td>მობილური</td>" + "<td>სამუშაო სფერო</td>"
							+ "<td>კომპანია</td>" + "<td>პოზიცია</td>" + "<td>ხელფასი</td>" + "<td>სტატუსი</td>"
							+ "</tr>" + "<tr>" + "<td>" + onlineApp.getId() + "</td>" + "<td>"
							+ Math.round(onlineApp.getLoanAmount() * 100.0) / 100.0 + "</td>" + "<td>"
							+ onlineApp.getLoanPeriod() + "</td>" + "<td>" + onlineApp.getName() + "</td>" + "<td>"
							+ onlineApp.getBirthDate() + "</td>" + "<td>" + onlineApp.getPrivateNumber() + "</td>"
							+ "<td>" + onlineApp.getMobileNumber() + "</td>" + "<td>" + onlineApp.getWorkSphere()
							+ "</td>" + "<td>" + onlineApp.getCompanyName() + "</td>" + "<td>"
							+ onlineApp.getWorkPosition() + "</td>" + "<td>" + onlineApp.getSalary() + "</td>" + "<td>"
							+ getNameForStatus(onlineApp.getStatus()) + "</td>" + "</tr>"
							+ "<tr style=\"background-color:Coral; height: 20px; font-weight: bold;\">"
							+ "<td>მუშ.ხან.</td>" + "<td>დამ.შემოსავალი</td>" + "<td>თვ.გადასახდელი</td>"
							+ "<td>ოჯახ.მდგომ.</td>" + "<td>შვილები</td>" + "<td>დასაქ.ოჯახ.წევრები</td>"
							+ "<td>საერთო შემოსავალი</td>" + "<td>თარიღი</td>" + "<td>ინკასო</td>"
							+ "<td align=\"center\">კომენტარები</td><td align=\"center\">აპლიკაციის დამატება</td><td align=\"center\">აპლიკაციის უარყოფა</td>"
							+ "</tr>" + "<tr>" + "<td>" + onlineApp.getWorkPeriod() + "</td>" + "<td>"
							+ onlineApp.getOtherIncome() + "</td>" + "<td>" + onlineApp.getAmountToPayOnOtherLoans()
							+ "</td>" + "<td>" + onlineApp.getMaritalStatus() + "</td>" + "<td>"
							+ onlineApp.getNumberOfChildren() + "</td>" + "<td>" + onlineApp.getEmployedFamilyMembers()
							+ "</td>" + "<td>" + onlineApp.getTotalFamilyIncome() + "</td>" +
							"<td>"+(onlineApp.isIncaso() ? "ინკასო":"არ ადევს")+"</td>" +
							"<td>" + tf.millisecondsToDateStr(onlineApp.getAdditionTime()) + "</td>"
							+ "<td onclick=\"triggerComments(" + onlineApp.getId() + "," + consCompId
							+ ")\"><img height=\"20px\" width=\"20px\" src=\"" + request.getContextPath()
							+ "/resources/images/comment.png\"></td>"
							+ "<td bgcolor=\"lightgreen\" onclick=\"acceptApplication(" + onlineApp.getId() + ","
							+ consCompId + ")\"><img height=\"20px\" width=\"20px\" src=\"" + request.getContextPath()
							+ "/resources/images/accept.png\"></td>"
							+ "<td bgcolor=\"LightCoral\" onclick=\"rejectApplication(" + onlineApp.getId() + ","
							+ consCompId + ")\"><img height=\"20px\" width=\"20px\" src=\"" + request.getContextPath()
							+ "/resources/images/reject.png\"></td>" + "</tr>"
							+ "<tr><td colspan=\"3\">" + onlineApp.getLoanPurpose() + "</td><td colspan=\"5\" align=\"left\"> " + onlineApp.getBranchOfficeName() + "</td></tr>"
							+ "</table>" + "<br>");
				} else {
					ret.append("<br>"
							+ "<table style=\"width:100%; height: 180px; border: 1px solid black; text-align:center; border-collapse: collapse; spacing: 5px;\">"
							+ "<tr style=\"background-color:Coral; height: 20px; font-weight: bold;\">" + "<td>ID</td>"
							+ "<td>თანხა</td>" + "<td>პერიოდი</td>" + "<td>სახელი გვარი</td>" + "<td>დაბ.თარიღი</td>"
							+ "<td>პირადი ნომ.</td>" + "<td>მობილური</td>" + "<td>სამუშაო სფერო</td>"
							+ "<td>კომპანია</td>" + "<td>პოზიცია</td>" + "<td>ხელფასი</td>" + "<td>სტატუსი</td>"
							+ "</tr>" + "<tr>" + "<td>" + onlineApp.getId() + "</td>" + "<td>"
							+ Math.round(onlineApp.getLoanAmount() * 100.0) / 100.0 + "</td>" + "<td>"
							+ onlineApp.getLoanPeriod() + "</td>" + "<td>" + onlineApp.getName() + "</td>" + "<td>"
							+ onlineApp.getBirthDate() + "</td>" + "<td>" + onlineApp.getPrivateNumber() + "</td>"
							+ "<td>" + onlineApp.getMobileNumber() + "</td>" + "<td>" + onlineApp.getWorkSphere()
							+ "</td>" + "<td>" + onlineApp.getCompanyName() + "</td>" + "<td>"
							+ onlineApp.getWorkPosition() + "</td>" + "<td>" + onlineApp.getSalary() + "</td>" + "<td>"
							+ getNameForStatus(onlineApp.getStatus()) + "</td>" + "</tr>"
							+ "<tr style=\"background-color:Coral; height: 20px; font-weight: bold;\">"
							+ "<td>მუშ.ხან.</td>" + "<td>დამ.შემოსავალი</td>" + "<td>თვ.გადასახდელი</td>"
							+ "<td>ოჯახ.მდგომ.</td>" + "<td>შვილები</td>" + "<td>დასაქ.ოჯახ.წევრები</td>"
							+ "<td>საერთო შემოსავალი</td>" + "<td>თარიღი</td>" + "<td>ინკასო</td>"
							+ "<td colspan=\"3\" align=\"center\">კომენტარები</td>" + "</tr>" + "<tr>" + "<td>"
							+ onlineApp.getWorkPeriod() + "</td>" + "<td>" + onlineApp.getOtherIncome() + "</td>"
							+ "<td>" + onlineApp.getAmountToPayOnOtherLoans() + "</td>" + "<td>"
							+ onlineApp.getMaritalStatus() + "</td>" + "<td>" + onlineApp.getNumberOfChildren()
							+ "</td>" + "<td>" + onlineApp.getEmployedFamilyMembers() + "</td>" + "<td>"
							+ onlineApp.getTotalFamilyIncome() + "</td>" + "<td>"
							+ "<td>"+(onlineApp.isIncaso() ? "ინკასო":"არ ადევს")+"</td>"
							+ tf.millisecondsToDateStr(onlineApp.getAdditionTime()) + "</td>"
							+ "<td colspan=\"3\" onclick=\"triggerComments(" + onlineApp.getId() + "," + consCompId
							+ ")\"><img height=\"20px\" width=\"20px\" src=\"" + request.getContextPath()
							+ "/resources/images/comment.png\"></td>"
							+ ((onlineApp.getStatus() != 2)
									? "<td colspan=\"4\" onclick=\"changeStatus(" + onlineApp.getId() + "," + consCompId
											+ "," + 0 + ")\"><img height=\"20px\" width=\"20px\" src=\""
											+ request.getContextPath()
											+ "/resources/images/resume.png\"  title=\"აპლიკაციაში დაბრუნება\"></td>"
									: "")
							+ "</tr>" + "<tr><td colspan=\"3\" align=\"left\"> " + onlineApp.getBranchOfficeName()
							+ "</td></tr>" + "</table>" + "<br>");
				}
			}
			return ret.toString();
		} catch (Exception e) {
			e.printStackTrace();
			return "სესხის სტატუსის შეცვლისას დაფიქსირდა შეცდომა: " + e.toString();
		}
	}
