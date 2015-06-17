defmodule ApiDemo.Api.V1.SubscriberView do
  use ApiDemo.Web, :view

  # def render("index.json", %{subscribers: subscribers}) do
  #   subscribers
  # end

  def render("show.json", %{subscriber: subscriber}) do
    format(%{subscriber: subscriber})
  end

  defp format(%{subscriber: subscriber}) do
    [
      %{
        phone_number: subscriber.phone_number,
        created_at: subscriber.inserted_at,
        updated_at: subscriber.updated_at,
      }
    ]
  end

end
