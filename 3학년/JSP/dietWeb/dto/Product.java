package dto;

import java.io.Serializable;

public class Product implements Serializable {
	
	public Product(String productId, String pname, Integer unitPrice, String description, String category, String manufacturer, double calorie, Integer volume, String filename) {
		super();
		this.productId=productId;
		this.pname=pname;
		this.unitPrice=unitPrice;
		this.description=description;
		this.category=category;
		this.manufacturer=manufacturer;
		this.calorie=calorie;
		this.volume=volume;
		this.filename=filename;
		
	}
	
	private static final long serialVersionUID=-4274700572038677000L;
	
	private String productId;	//상품 아이디
	private String pname;	//상품명
	private Integer unitPrice;		//상품 가격
	private String description;		//상품 설명
	private String manufacturer;		//제조사
	private String category;	//분류
	private double calorie;	//칼로리
	private Integer volume;	//무게
	private String filename;	//이미지 파일명
	private int quantity;	//장바구니에 담은 개수

	public Product() {
		super();
	}

	public String getProductId() {
		return productId;
	}

	public double getCalorie() {
		return calorie;
	}

	public void setCalorie(float calorie) {
		this.calorie = calorie;
	}

	public Integer getVolume() {
		return volume;
	}

	public void setVolume(Integer volume) {
		this.volume = volume;
	}

	public void setProductId(String productId) {
		this.productId = productId;
	}

	public String getPname() {
		return pname;
	}

	public void setPname(String pname) {
		this.pname = pname;
	}

	public Integer getUnitPrice() {
		return unitPrice;
	}

	public void setUnitPrice(Integer unitPrice) {
		this.unitPrice = unitPrice;
	}

	public String getDescription() {
		return description;
	}

	public void setDescription(String description) {
		this.description = description;
	}

	public String getManufacturer() {
		return manufacturer;
	}

	public void setManufacturer(String manufacturer) {
		this.manufacturer = manufacturer;
	}

	public String getCategory() {
		return category;
	}

	public void setCategory(String category) {
		this.category = category;
	}
	
	public String getFilename() {
		return filename;
	}
	
	public void setFilename(String filename) {
		this.filename = filename;
	}

	public int getQuantity() {
		return quantity;
	}

	public void setQuantity(int quantity) {
		this.quantity = quantity;
	}
}
