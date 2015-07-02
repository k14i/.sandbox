defmodule ApiDemo.Subscriber do
  use Ecto.Model
  import Ecto.Query
  alias ApiDemo.Repo
  alias ApiDemo.Subscriber

  # validate_type!(:string, subscriber.phone_number)
  # Ecto.validate_unique Subscriber, phone_number: phone_number
  # validate subscriber,
  #   phone_number: present()
  #   sim_id: present()
  #   status: present()

  schema "subscribers" do
    field :phone_number, :string
    field :sim_id, :string
    field :status, :string, default: "active"
    # field :contracted_at, :datetime, default: nil
    # field :terminated_at, :datetime, default: nil
    timestamps
  end

  defp limit scope do
    Application.get_env(:api_demo, ApiDemo.Subscriber)[scope][:limit]
  end

  def list limit \\ limit :list do
    query = from s in Subscriber,
      where: s.status == "active",
      limit: ^limit,
      select: s
    Repo.all query
    # Repo.all Subscriber
  end

  def get %{phone_number: phone_number} do
    query = from s in Subscriber,
      where: s.phone_number == ^phone_number,
      select: s
    Repo.all query
    # Repo.get_by! Subscriber, phone_number: phone_number
  end

end
